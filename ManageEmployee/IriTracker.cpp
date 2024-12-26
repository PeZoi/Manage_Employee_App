#include "IriTracker.h"
#include "IriLivenessBase.h"
#include "Iddk2000_features.h"
#include "DatabaseSingleton.h"
#include "IriTrackerSingleton.h"
#include <QString>
#include <QIODevice>
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <utility>
#include <QThread>

bool flagCheckFirstOpenDevice = false;

IriTracker::IriTracker()
{
}

bool process_matching_result_custom(float distance, char* enrollID)
{
	//Success case
	if (distance <= 1.0f)//Match
	{
		if (enrollID)
			printf("\nMatched with '%s'!!!\n", enrollID);
		else {
			qDebug() << "Matched";
			return true;
		}
	}
	else if (distance > 1.1f)// Non-match
	{
		//qDebug() << "No match found";
	}
	else//greyzone
	{
		// Grey Zone: we are not sure about the result due to bad image quality, users should make a capture again ...
		qDebug() << "The quality of this image may be not good enough.\r\nPlease re-capture another image and try again!";
	}
	return false;
}

void clear_capture_custom()
{
	IddkResult iRet = IDDK_OK;
	// default to clear both captured eyes for binocular device
	iRet = Iddk_ClearCapture(g_hDevice, IDDK_UNKNOWN_EYE);
	if (iRet == IDDK_OK)
	{
		//printf("Clear capture successfully\n");
	}
	else
	{
		printf("Clear capture failed \n");
		handle_error(iRet);
	}
}

bool check_image_quality_custom(bool forEnrollment, bool& isGrayZone, int& numAcceptableEyes)
{
	bool bRet = false;
	IddkIrisQuality* pQualities = NULL;
	int nQualityCount = 0;
	numAcceptableEyes = 0;
	int nBadTotalScore = forEnrollment ? 50 : 30;
	int nBadUsableArea = forEnrollment ? 50 : 30;
	int nGoodTotalScore = 70;
	int nGoodUsableArea = 70;

	IddkResult iRet = Iddk_GetResultQuality(g_hDevice, &pQualities, &nQualityCount);

	if (iRet == IDDK_OK || iRet == IDDK_SE_LEFT_FRAME_UNQUALIFIED || iRet == IDDK_SE_RIGHT_FRAME_UNQUALIFIED)
	{
		if (forEnrollment)
		{
			// at least one eye's quality is in grayzone
			isGrayZone = ((pQualities[RIGHT_EYE_IDX].totalScore > nBadTotalScore && pQualities[RIGHT_EYE_IDX].usableArea > nBadUsableArea
				&& (pQualities[RIGHT_EYE_IDX].totalScore <= nGoodTotalScore || pQualities[RIGHT_EYE_IDX].usableArea <= nGoodUsableArea))
				|| (pQualities[LEFT_EYE_IDX].totalScore > nBadTotalScore && pQualities[LEFT_EYE_IDX].usableArea > nBadUsableArea
					&& (pQualities[LEFT_EYE_IDX].totalScore <= nGoodTotalScore || pQualities[LEFT_EYE_IDX].usableArea <= nGoodUsableArea)));
		}
		else
		{
			//For verification there is no grayzone, just one threshold (30) 
			isGrayZone = false;
		}

		// number of eyes with acceptable quality (not bad)
		if (pQualities[RIGHT_EYE_IDX].totalScore > nBadTotalScore && pQualities[RIGHT_EYE_IDX].usableArea > nBadUsableArea)
			numAcceptableEyes++;

		if (pQualities[LEFT_EYE_IDX].totalScore > nBadTotalScore && pQualities[LEFT_EYE_IDX].usableArea > nBadUsableArea)
			numAcceptableEyes++;

		if (numAcceptableEyes == 0)
		{
			//Clear all captured iris images in the camera device
			Iddk_ClearCapture(g_hDevice, IDDK_UNKNOWN_EYE);
			printf("\nNo captured iris image has acceptable quality for the %s. Please try to capture your iris(es) again!\n", forEnrollment ? "enrollment" : "matching");
			bRet = false;
			goto RETSEC;
		}

		if (g_isBinocular)
		{
			if (iRet != IDDK_SE_RIGHT_FRAME_UNQUALIFIED && (pQualities[RIGHT_EYE_IDX].totalScore <= nBadTotalScore || pQualities[RIGHT_EYE_IDX].usableArea <= nBadUsableArea))
			{
				// clear right eye
				if (Iddk_ClearCapture(g_hDevice, IDDK_RIGHT_EYE))
				{
					bRet = false;
					goto RETSEC;
				}
				printf("\nThe right iris image has bad quality. It was cleared!\n");
			}
			if (iRet != IDDK_SE_LEFT_FRAME_UNQUALIFIED && (pQualities[LEFT_EYE_IDX].totalScore <= nBadTotalScore || pQualities[LEFT_EYE_IDX].usableArea <= nBadUsableArea))
			{
				// clear left eye
				if (Iddk_ClearCapture(g_hDevice, IDDK_LEFT_EYE))
				{
					bRet = false;
					goto RETSEC;
				}
				printf("\nThe left iris image has bad quality. It was cleared!\n");
			}
		}
	}
	else
	{
		handle_error(iRet);
		goto RETSEC;
	}
	bRet = true;
RETSEC:
	reset_error_level(iRet);
	return bRet;
}

void IriTracker::get_device() {
	int i = 0;
	int option = -1;
	IddkConfig config;
	IddkResult iRet = IDDK_OK;
	unsigned int baudrate = 115200;
	const char** ppDeviceDescs = NULL;
	int nDeviceCnt = 0;
	char buffer[256];


	/* We should get the current configuration before setting new one */
	iRet = Iddk_GetSdkConfig(&config);
	if (iRet != IDDK_OK)
	{
		/* Oops ! Something wrong happens */
		goto RETSEC;
	}

	/* Now we check the configuration of the currently attached device to change the SDK configuration accordingly */
	config.commStd = IDDK_COMM_USB;
	//g_isUsbDevice = true;

	// Reset device
	config.resetOnOpenDevice = 1;

	/* Set new SDK configuration */
	iRet = Iddk_SetSdkConfig(&config);
	if (iRet != IDDK_OK)
	{
		printf("\nFailed to set new configuration !\n");
		qDebug() << "Failed to set new configuration";
		//return;
		goto RETSEC;
	}

	/* Now, we can open the device and retrieve the handle */
	/* If USB, we should scan devices first */
	while (true) {
		QThread::msleep(500);
		//qDebug() << "Scan device...";

		iRet = Iddk_ScanDevices(&ppDeviceDescs, &nDeviceCnt);
		if (iRet != IDDK_OK)
		{
			if (iRet == IDDK_DEVICE_NOT_FOUND)
			{
				//qDebug() << " ==> No IriTech devices found.";
			}
			else if (iRet == IDDK_DEVICE_IO_FAILED) {
				qDebug() << " ==> Connect fail to device.";
			}
			goto RETSEC;
		}

		for (i = 0; i < nDeviceCnt; i++)
		{
			printf("\t%d. %s\n", i + 1, ppDeviceDescs[i]);
		}

		/* Open the first found device */
		if (!flagCheckFirstOpenDevice) {
			iRet = Iddk_OpenDevice(ppDeviceDescs[0], &g_hDevice);

		}
		if (iRet == IDDK_OK)
		{
			//qDebug() << "==> Device found!.";
			// check type of device is monocular or binocular
			IddkDeviceInfo deviceInfo;
			if (IDDK_OK == Iddk_GetDeviceInfo(g_hDevice, &deviceInfo))
			{
				g_isBinocular = deviceInfo.isBinocular;
			}
			emit foundDevice(true);
			flagCheckFirstOpenDevice = true;
			IriTrackerSingleton::isFoundDevice = true;
			continue;
		}
		else if (iRet == IDDK_DEVICE_ALREADY_OPEN && flagCheckFirstOpenDevice == false)
		{
			Iddk_CloseDevice(g_hDevice);
			goto RETSEC;
		}
		else {
			goto RETSEC;
		}

	RETSEC:
		if (iRet != IDDK_OK)
		{
			handle_error(iRet);
		}

		reset_error_level(iRet);
		if (!flagCheckFirstOpenDevice) {
			emit foundDevice(false);
		}
		flagCheckFirstOpenDevice = false;
		IriTrackerSingleton::isFoundDevice = false;
		g_hDevice = NULL;
		ppDeviceDescs = NULL;
		nDeviceCnt = 0;

	}

	QThread::msleep(1000);
}

void IriTracker::run(bool bDefaultParams, bool bMultiple, bool bProcessResult)
{
	/*Params default*/
	/*bool bDefaultParams = false;
	bool bMultiple = true;
	bool bProcessResult = true;*/

	/* For streaming images */
	IddkImage* pImages = NULL;
	int nMaxEyeSubtypes = 0;
	IddkEyeSubtype eyeSubtype = IDDK_UNKNOWN_EYE;

	/* Parameters for capturing */
	IddkCaptureMode captureMode = IDDK_TIMEBASED;
	IddkQualityMode qualityMode = IDDK_QUALITY_NORMAL;
	bool autoLeds = true;
	bool bStreamMode = true;
	int iCount = 3;

	/* Other params */
	IddkResult iRet = IDDK_OK;
	IddkCaptureStatus captureStatus = IDDK_IDLE;
	bool bRun = true;
	int imageWidth = 640, imageHeight = 480;
	int i = 0;
	bool eyeDetected = false;
	int option = -1;
	int times = 0;

	IddkIrisQuality* pQualities;
	int nQualityCount = 0;

	bool flagBreak = false; // In case dialog close, using this to break loop

	/* We have to init camera first */
	iRet = Iddk_InitCamera(g_hDevice, &imageWidth, &imageHeight);
	qDebug() << "IRet: " << iRet;
	if (iRet != IDDK_OK)
	{
		handle_error(iRet);
		return;
	}

	/* OK, we capture many times until user exits */
	while (bDefaultParams ? IriTrackerSingleton::isRunningStreamThreadCheckInOut : true)
	{
		/* Init variables in inner loop */
		i = 0;
		bRun = true;
		eyeDetected = false;
		times++;

		if (!bDefaultParams)
		{
			prepare_param_for_capturing(captureMode, qualityMode, eyeSubtype, autoLeds, iCount);
		}

		/* Now, we capture user's eyes */
		iRet = Iddk_StartCapture(g_hDevice, captureMode, iCount, qualityMode, IDDK_AUTO_CAPTURE, eyeSubtype, autoLeds, NULL, NULL);


#ifdef _MSC_VER
		/******************************************************************************************/
		/* Below is an example how to use the Iddk_StartCapture with a callback function to get stream images*/
		/*
		HANDLE hEvent = CreateEvent(0, FALSE, FALSE, 0);
		iRet = Iddk_StartCapture(g_hDevice, captureMode, iCount, qualityMode, IDDK_AUTO_CAPTURE, eyeSubtype, autoLeds, capture_proc, hEvent);
		if(iRet != IDDK_OK)
		{
			handle_error(iRet);
		}

		WaitForSingleObject(hEvent, 30000);

		Iddk_StopCapture(g_hDevice);

		return;
		*/
#endif

		if (iRet != IDDK_OK)
		{
			/* Remember to deinit camera */
			handle_error(iRet);
			goto RETSEC;
		}
		reset_error_level(iRet);
		/*
		Start a loop to check the device status.
		(You can use the callback function capture_proc instead of this while loop).
		*/


		qDebug() << "Scanning for eyes";
		while (bRun)
		{
			if (bDefaultParams ? !IriTrackerSingleton::isRunningStreamThreadCheckInOut : false) {
				break;
			}
			if (bStreamMode)
			{
				iRet = Iddk_GetStreamImage(g_hDevice, &pImages, &nMaxEyeSubtypes, &captureStatus);
 				if (iRet == IDDK_OK)
				{
					//TODO/////////////////////////////////////////////////////////////////
					//
					// Your code to process stream image.
					// 230523
					//////////////////////////////////////////////////////////////////////
					emit imageProcessed(pImages->imageData, pImages->imageDataLen, pImages->imageWidth, pImages->imageHeight);
				}
				//If the stream image is not allowed by device configuration
				else if (iRet == IDDK_DEV_FUNCTION_DISABLED)
				{
					bStreamMode = false;
					iRet = Iddk_GetCaptureStatus(g_hDevice, &captureStatus);
				}
				else if (iRet == IDDK_SE_NO_FRAME_AVAILABLE)
				{
					// when Iddk_GetStreamImage returns IDDK_SE_NO_FRAME_AVAILABLE, there are 2 possibilities:
					// 1. The capturing process ended.
					// 2. The capturing process has not started yet
					//So try to check capturing status to know which above possiblity is:
					iRet = Iddk_GetCaptureStatus(g_hDevice, &captureStatus);
				}
			}
			else
			{
				iRet = Iddk_GetCaptureStatus(g_hDevice, &captureStatus);
				wait(100);
			}
			/* If GetStreamImage and GetCaptureStatus cause no error, process the capture status.*/
			if (iRet == IDDK_OK)
			{
				if (captureStatus == IDDK_CAPTURING)
				{
					if (!eyeDetected)
					{
						qDebug() << "Eyes are detected.";
						eyeDetected = true;
					}
				}
				else if (captureStatus == IDDK_COMPLETE)
				{
					/* capture has finished */
					bRun = false;
				}
				else if (captureStatus == IDDK_ABORT)
				{
					/* capture has been aborted */
					qDebug() << "Capture aborted";
					bRun = false;
				}
				else
				{
					printf(".");
					/* We set up a counter to break the loop if user doesn't place the eyes in front of the camera */
					i++;
					if (i > 50)
					{
						i = 0;
						qDebug() << "Oops! No eye detected for so long. The capture process aborted.";
						if (bDefaultParams == false && isCancelDialogEmployee) { // DialogEmployee using
							flagBreak = true;
							break;
						}
					}
				}

				//reset_error_level(iRet);
			}
			else
			{
				/* handle error and terminate this capture */
				//handle_error(iRet);
				bRun = false;
			}
		}

		if (flagBreak) {
			break;
		}

		/* Try to stop capturing*/
		iRet = Iddk_StopCapture(g_hDevice);
		if (iRet != IDDK_OK)
		{
			//handle_error(iRet);
			//goto RETSEC;
		}

		// check liveness of captured images.
		//std::vector<IriLivenessDetector::LivenessResult> livenessResults;
  //      float decisionValue = 0;
  //      int ret = Iddk_CheckLivenessResultImage(g_hDevice, livenessResults);
  //      if (ret == IRI_LN_OK || 
  //          ret == IddkResult::IDDK_SE_RIGHT_FRAME_UNQUALIFIED || 
  //          ret == IddkResult::IDDK_SE_LEFT_FRAME_UNQUALIFIED)
  //      {
		//	// check liveness OK
  //      }
  //      else
  //      {
  //          printf("\nCheck Liveness Result Image: %d ", ret);
  //          printf("\n");
  //      }
		//~check liveness.


		qDebug() << "The capture process completed";
		//reset_error_level(iRet);
		iRet = Iddk_GetResultQuality(g_hDevice, &pQualities, &nMaxEyeSubtypes);
		if (iRet == IDDK_OK)
		{
			if (nMaxEyeSubtypes == 1)//monocular device model
			{
				printf("Quality of the current captured image:\n\t1. Total score: %d\n\t2. Usable area: %d\n\t",
					pQualities[0].totalScore, pQualities[0].usableArea);
			}
			else// binocular device model (nMaxEyeSubtypes == 2)
			{
				printf("Quality of the current captured images:\n\t");
				printf("1. Total score of the right eye: %d\n\t2. Usable area of the right eye: %d\n\t",
					pQualities[RIGHT_EYE_IDX].totalScore, pQualities[RIGHT_EYE_IDX].usableArea);
				printf("4. Total score of the left eye: %d\n\t5. Usable area of the left eye: %d\n\t",
					pQualities[LEFT_EYE_IDX].totalScore, pQualities[LEFT_EYE_IDX].usableArea);
			}
		}
		/*
		else if (iRet == IDDK_SE_LEFT_FRAME_UNQUALIFIED)
		{
			// binocular device model
			printf("Left eye image is not qualified. Quality of the current captured image:\n\t");
			printf("1. Total score of right eye: %d\n\t2. Usable area of right eye: %d\n\t",
				pQualities[RIGHT_EYE_IDX].totalScore, pQualities[RIGHT_EYE_IDX].usableArea);
		}
		else if (iRet == IDDK_SE_RIGHT_FRAME_UNQUALIFIED)
		{
			// binocular device model
			printf("Right eye image is not qualified. Quality of the current captured image:\n\t");
			printf("1. Total score of left eye: %d\n\t2. Usable area of left eye: %d\n\t",
				pQualities[LEFT_EYE_IDX].totalScore, pQualities[LEFT_EYE_IDX].usableArea);
		}
		*/
		else
		{
			bRun = true;
			continue;
			//handle_error(iRet);
			//goto RETSEC;
		}
		//reset_error_level(iRet);
		qDebug() << "Preparing save template.";
		if (bProcessResult && captureStatus == IDDK_COMPLETE)
		{
			qint64 timestamp = QDateTime::currentDateTime().toSecsSinceEpoch();
			/* Get the result image */
			IddkImage* result = get_result_image_custom(timestamp);
			emit imageResult(result->imageData, result->imageDataLen, result->imageWidth, result->imageHeight);
			//get_result_ISO_image(times);

			/* Get the result template */
			IddkDataBuffer templateDataBuffer = get_result_template_custom(timestamp);
			emit resultTemplate(templateDataBuffer.data, templateDataBuffer.dataSize);
			clear_capture_custom();
			break;
		}

		/* iris_recognition calls, we break the loop */
		if (!bMultiple)
		{
			goto RETSEC;
		}

		bRun = true;

		/* Number of capturing */
		times++;
	}

RETSEC:
	/* Finally, we deinit the camera */
	iRet = Iddk_DeinitCamera(g_hDevice);
	if (iRet != IDDK_OK)
	{
		handle_error(iRet);
	}
	reset_error_level(iRet);
}

void IriTracker::scan_iri()
{
	while (true)
	{
		if (!IriTrackerSingleton::isFoundDevice) {
			QThread::msleep(500);
			continue;
		}
		// SCAN
		{
			IddkResult iRet = IDDK_OK;
			IddkCaptureStatus captureStatus;
			iRet = Iddk_GetCaptureStatus(g_hDevice, &captureStatus);

			if (iRet == IDDK_OK)
			{
				reset_error_level(iRet);
				if (captureStatus != IDDK_COMPLETE)
				{
					if (IriTrackerSingleton::isRunningStreamThreadCheckInOut) {
						run(true, false, false);
						checkTemplates(); // CHECKING
					}
				}
			}
		}
		QThread::msleep(2000);
	}
}


bool IriTracker::checkTemplates() {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();
	QList<QPair<QString, QPair<QByteArray, QByteArray>>> employeeIriesList = DatabaseSingleton::getInstance()->getDB()->getEmployeeRepository()->getAllIri();
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();


	for (QPair<QString, QPair<QByteArray, QByteArray>> employeeIries : employeeIriesList) {
		float compareDis = 1000.0f;
		float minDis = 3.0f;
		int nComparisonResults = 0;
		IddkComparisonResult* pComparisonResults = NULL;
		IddkResult iRet = IDDK_OK;
		int option = 0;
		IddkCaptureStatus captureStatus = IDDK_IDLE;
		char enrollID[255];
		int i = 0;
		IddkDataBuffer pEnrollTemplate;
		char templateFile[256];
		char temp[256];
		char minEnrollID[32];
		/* Compare1N */
		char sMaxDistance[100];
		// default maxDistance = 0: return all distances
		float fMaxDistance = 0;
		nComparisonResults = 0;
		pComparisonResults = NULL;

		// INIT pEnrollTemplate
		pEnrollTemplate.data = nullptr;

		/* Remember that before doing any identification or verification,
		we should check the quality of the current captured image */
		bool isGrayZone = false;
		int numAcceptableEyes = 0;
		/*if (!check_image_quality_custom(false, isGrayZone, numAcceptableEyes))
		{
			continue;
		}*/

		for (int i = 0; i < 2; i++) {
			QByteArray iri;
			/* Init */
			if (i == 0) {
				iri = employeeIries.second.first; // IRI LEFT
			}
			else {
				iri = employeeIries.second.second; // IRI RIGHT
			}
			pEnrollTemplate.dataSize = iri.size();
			if (pEnrollTemplate.dataSize > 0) {
				pEnrollTemplate.data = new unsigned char[pEnrollTemplate.dataSize];
				memcpy(pEnrollTemplate.data, iri.constData(), pEnrollTemplate.dataSize);
			}
			else {
				if (pEnrollTemplate.data != nullptr) {
					delete[] pEnrollTemplate.data;
				}
				pEnrollTemplate.data = nullptr;
				pEnrollTemplate.dataSize = 0;
			}


			iRet = Iddk_Compare11WithTemplate(g_hDevice, &pEnrollTemplate, &compareDis);
			if (iRet == IDDK_OK)
			{
				if (!process_matching_result_custom(compareDis, NULL)) {
					continue;
				}
				qDebug() << "Done. Compare Distance = " << compareDis;

				emit isCheckCompareSuccess(employeeIries.first);
				clear_capture_custom();

				return true;
			}
			else if (iRet == IDDK_GAL_EMPTY)
			{
				qDebug() << "No match found. The gallery is empty !";
			}
			else if (iRet == IDDK_SE_NO_QUALIFIED_FRAME)
			{
				qDebug() << "Failed. No qualified image";
			}
			else
			{
				qDebug() << "Failed";
				handle_error(iRet);
			}
			reset_error_level(iRet);
		}
	}
	qDebug() << "No match found";
	clear_capture_custom();
	return false;
}
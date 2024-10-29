#include "IriTracker.h"
#include <QString>
#include <QIODevice>
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <utility>

QString path = "D://IriTech//Code//ManageEmployee//image//";
QString imgReturn = "";

IriTracker::IriTracker()
{
}

int write_binary_file(const QString& fname, const void* buff, unsigned len)
{
	QFile file(fname);
	if (file.open(QIODevice::WriteOnly))
	{
		qint64 written = file.write(reinterpret_cast<const char*>(buff), len);
		file.close();
		return written == len ? 0 : 1;
	}
	return 1; // failure
}
void generate_time_string(QString& timestamp)
{
	timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
}


void log_lib_error(int fail)
{
	qDebug() << "Library error:" << IIC_GetErrorName(fail);
}


IICHandle open_first_device(const char devicePaths[][256], int deviceCount)
{
	for (int i = 0; i < deviceCount; ++i)
	{
		IICHandle hdev = 0;
		int fail = IIC_OpenDevice(devicePaths[i], NULL, &hdev);
		if (fail)
		{
			log_lib_error(fail);
			printf("...while open device: %s\n", devicePaths[i]);
			continue;
		}
		return hdev;
	}
	return 0;
}

const char* translate_capture_status(int sttValue)
{
	switch (sttValue)
	{
	case CAPTURE_STATUS_IDLE:
		return "idle";
	case CAPTURE_STATUS_READY:
		return "ready";
	case CAPTURE_STATUS_CAPTURING:
		return "capturing";
	case CAPTURE_STATUS_COMPLETE:
		return "complete";
	case CAPTURE_STATUS_ABORT:
		return "aborted";
	case CAPTURE_STATUS_FAILED_TO_CAPTURE:
		return "failed to capture";
	default:
		return "invalid value";
	}
}

const char* translate_quality_metric_index(int idx)
{
	switch (idx)
	{
	case IRIS_QM_TOTAL_SCORE:
		return "Total score";
	case IRIS_QM_USABLE_AREA:
		return "Usable area";
	case IRIS_QM_LOWER_USABLE_AREA:
		return "Lower usable area";
	default:
		return "Unknown metric";
	}
}

int query_result_image(IICHandle hDevice)
{
	int fail = 0;

	// result image: PNG for saving and viewing
	const unsigned char* imageData;
	int imageLen, imageWidth, imageHeight;
	fail = IIC_GetResultImage(hDevice,
		EYE_SUBTYPE_UNDEF,
		ADDITIONAL_IMAGE_HEADER_NONE,
		1, // fill image quality score
		IMAGE_FORMAT_MONO_PNG,
		IRIS_IMAGE_KIND_K2,
		IMAGE_COMPRESSION_CRITERIA_BY_QUALITY,
		100,
		&imageData, &imageLen, &imageWidth, &imageHeight);
	if (fail)
	{
		qDebug() << "Failed to get result image!";
		log_lib_error(fail);
		return fail;
	}

	QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
	QString fileName = QString("%1.png").arg(timestamp);

	QFile file(path + fileName);
	if (!file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Failed to write file:" << fileName;
		return 1;
	}

	if (file.write(reinterpret_cast<const char*>(imageData), imageLen) != imageLen)
	{
		qDebug() << "Failed to write file:" << fileName;
		return 1;
	}

	qDebug() << "Result image saved to file:" << fileName;
	file.close();

	imgReturn = path + fileName;

	// result image: ISO spec 2011
	fail = IIC_GetResultImage(hDevice,
		EYE_SUBTYPE_UNDEF,
		ADDITIONAL_IMAGE_HEADER_ISO2011,
		1, // fill image quality score
		IMAGE_FORMAT_MONO_JPEG2000,
		IRIS_IMAGE_KIND_K7,
		IMAGE_COMPRESSION_CRITERIA_BY_QUALITY,
		100,
		&imageData, &imageLen, &imageWidth, &imageHeight);
	if (fail)
	{
		qDebug() << "Failed to get result ISO image!";
		log_lib_error(fail);
		return fail;
	}

	QString isoFileName = QString("%1_iso2011.bin").arg(timestamp);

	QFile isoFile(path + isoFileName);
	if (!isoFile.open(QIODevice::WriteOnly))
	{
		qDebug() << "Failed to write file:" << isoFileName;
		return 1;
	}

	if (isoFile.write(reinterpret_cast<const char*>(imageData), imageLen) != imageLen)
	{
		qDebug() << "Failed to write file:" << isoFileName;
		return 1;
	}
	isoFile.close();
	qDebug() << "Result image saved to file:" << isoFileName;

	// show image quality score
	unsigned char irisQualityMetrics[3];
	int metricCount = 0;
	fail = IIC_GetResultImageQuality(hDevice, EYE_SUBTYPE_UNDEF,
		irisQualityMetrics,
		sizeof(irisQualityMetrics) / sizeof(irisQualityMetrics[0]),
		&metricCount);
	if (fail)
	{
		qDebug() << "Failed to get result image quality metrics!";
		log_lib_error(fail);
		return fail;
	}

	qDebug() << "Iris quality metrics:";
	for (int i = 0; i < metricCount; ++i)
	{
		qDebug() << "\t" << translate_quality_metric_index(i) << ":" << irisQualityMetrics[i];
	}

	return fail;
}

void iris_capturing_event_callback(
	void* callbackParam,              //callback parameter registered together with callback function.
	int* error,                       //report error code if that happens
	CaptureStatus* captureStatus,     //report current capture status
	int imageCount,                   //report number of streaming images received
	ImageFormat imageFormat,          //     format of streaming image
	EyeSubtype eyeSubtypes[],         //     eye label for each image
	const unsigned char* imageData[], //     image data of each one
	int imageLen[],                   //     image length of each one
	int imageWidth[],                 //     image width of each one
	int imageHeight[]                 //     image height of each one
)
{
	if (error || captureStatus)
	{
		CaptureStatus* statusPtr = (CaptureStatus*)callbackParam;
		if (error)
		{
			*statusPtr = CAPTURE_STATUS_ABORT;
		}
		if (captureStatus)
		{
			*statusPtr = (CaptureStatus)(*captureStatus);
		}
	}

	if (imageCount > 0)
	{
		for (int i = 0; i < imageCount; ++i)
		{
			//process streaming images (save, display...) if needed.
			// format: imageFormat,
			// image buffer : imageData[i],
			// image buffer length: imageLen[i],
			// image width: imageWidth[i],
			// image height: imageHeight[i]
		}
	}
	return;
}

int capture_with_callback(IICHandle hdev)
{
	CaptureStatus captureStatus = CAPTURE_STATUS_IDLE;
	CaptureCallbackOption callback = { iris_capturing_event_callback, &captureStatus,
		1, //preview?
		1, //downscale
		IMAGE_FORMAT_MONO_RAW, 100, //format & quality
		10 }; //frame rate (frames per second)
	int fail = IIC_StartCapturing(
		hdev,
		EYE_SUBTYPE_UNDEF,
		CAPTURE_TIMEOUT_MODE_TIMEBASED,
		3,
		true, //auto LED control
		true, //auto capture
		&callback);
	if (fail)
	{
		return fail;
	}

	/* wait until capture status changed to finish/aborted */
	while (captureStatus < CAPTURE_STATUS_COMPLETE)
	{
		sleep_msec(300);
	}

	printf("Last capture status: %s\n", translate_capture_status(captureStatus));
	if (captureStatus == CAPTURE_STATUS_COMPLETE)
	{
		return query_result_image(hdev);
	}

	return fail;
}

int capture_without_callback(IICHandle hdev)
{
	int fail = IIC_StartCapturing(hdev,
		EYE_SUBTYPE_UNDEF,
		CAPTURE_TIMEOUT_MODE_TIMEBASED, 3, true, true, NULL);
	if (fail)
	{
		return fail;
	}

	CaptureStatus captureStatus = CAPTURE_STATUS_IDLE;
	while (captureStatus < CAPTURE_STATUS_COMPLETE)
	{
		//switching this value to nonzero or 0, depending on your need
		const int NEED_STREAMING_IMAGES = 1;
		if (NEED_STREAMING_IMAGES)
		{
			int imageCount, imageLen[2], imageWidth[2], imageHeight[2];
			ImageFormat imageFormat;
			EyeSubtype eyeSubtypes[2];
			const unsigned char* imageData[2];

			fail = IIC_GetStreamingImages(
				hdev,
				1, //downscale factor
				IMAGE_FORMAT_MONO_RAW, 100,
				&captureStatus,
				&imageCount, &imageFormat, eyeSubtypes,
				imageData, imageLen, imageWidth, imageHeight);

			if (!fail && (imageCount > 0))
			{
				for (int i = 0; i < imageCount; ++i)
				{
					//process streaming images (save, display...) if needed.
					// format: imageFormat,
					// image buffer : imageData[i],
					// image buffer length: imageLen[i],
					// image width: imageWidth[i],
					// image height: imageHeight[i]
				}
			}
		}
		else
		{
			fail = IIC_GetCapturingStatus(hdev, &captureStatus);
		}

		//ignore failure: many reason: IO fail, no frame available
		if (captureStatus >= CAPTURE_STATUS_COMPLETE)
		{
			break;
		}
		else
		{
			//No-frame-available, memory failure: can ignore it
			if (!fail || (fail == BERR_NO_DATA) || (fail == BERR_NO_MEM))
			{
				continue;
			}
			else //more serious error
			{
				break;
			}
		}
		sleep_msec(100);
	}

	printf("Last capture status: %s\n", translate_capture_status(captureStatus));
	if (captureStatus == CAPTURE_STATUS_COMPLETE)
	{
		fail = query_result_image(hdev);
	}

	return fail;
}

QString IriTracker::run()
{

	int fail = 0;

	/* Library initialization */
	fail = IIC_Init();
	if (fail)
	{
		log_lib_error(fail);
		return "";
	}

	/* From here, library should be de-initialized to finish usage */
	do
	{
		/* find device list */
		char devicePaths[64][256]; /* find up to 64 devices, you can find more of them */
		int deviceCount = 0;
		fail = IIC_ScanDevices(COMM_CHANNEL_USB, devicePaths, 64, &deviceCount);
		if (fail)
		{
			log_lib_error(fail);
			break;
		}
		if (deviceCount <= 0)
		{
			printf("No device found!\n");
			break;
		}

		/* open first available device */
		IICHandle hdev = open_first_device(devicePaths, deviceCount);
		if (!hdev)
		{
			printf("No accessible device!\n");
			break;
		}

		/* capturing iris, callback approach */
		printf("--- capture with implementation using callback ---\n");
		fail = capture_with_callback(hdev);
		if (fail)
		{
			log_lib_error(fail);
		}

		/* capturing iris, caller does all query */
		/*printf("--- capture with implementation not using callback ---\n");
		fail = capture_without_callback(hdev);
		if (fail)
		{
		    log_lib_error(fail);
		}*/

		/* close device handle */
		IIC_CloseDevice(hdev);
		hdev = 0;

	} while (0);

	/* De-initialize library before exiting */
	IIC_Deinit();

	return imgReturn;
}

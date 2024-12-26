#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <QString>
#include <QObject>

class IriTracker : public QObject
{
	Q_OBJECT 

signals:
	void imageProcessed(unsigned char* imageData,
		int imageLen,
		int imageWidth,
		int imageHeight);

	void imageResult(unsigned char* imageData,
		int imageLen,
		int imageWidth,
		int imageHeight);

	void resultTemplate(const unsigned char* buffer, int size);
	void isCheckCompareSuccess(QString employeeId);

	void foundDevice(bool check);

public:
	IriTracker();
	void run(bool bDefaultParams, bool bMultiple, bool bProcessResult);
	void get_device();
	void scan_iri();
	bool checkTemplates();

	bool isCancelDialogEmployee = false;
};

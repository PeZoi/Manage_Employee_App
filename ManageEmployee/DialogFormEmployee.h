#pragma once
#include "ui_DialogFormEmployee.h"
#include "IriTracker.h"
#include "EmployeeModel.h"
#include <QMessageBox>

class DialogFormEmployee : public QDialog
{
	Q_OBJECT

public:
	DialogFormEmployee(QWidget* parent = nullptr);
	~DialogFormEmployee();
	Ui::DialogFormEmployeeClass getUi();

	bool isEditMode_employee = false;
	QString idSelected = "";
	QString avatarPath = "";
	QByteArray iri_rightPath = "";
	QByteArray iri_leftPath = "";

	QThread* captureThread = nullptr;
	IriTracker* iriTracker = nullptr;

	QString side = "LEFT";

signals:
	void submit(EmployeeModel employee, bool isEditMode, DialogFormEmployee* employeeView);
	void uploadAvatar(DialogFormEmployee* employeeForm, bool isEditMode_employee);

	void cancel();

public slots:
	void onClickCancel();
	void handleSubmit();
	void setMode(bool _isEditMode);
	void setValue(EmployeeModel employee);

	void processStreaming();
	void updateFrame(const unsigned char* imageData, int imageLen, int imageWidth, int imageHeight);
	void handleReciveTemplate(const unsigned char* buffer, int size);
	bool eventFilter(QObject* obj, QEvent* event);

	void switchImage(bool isFoundDevice);

private:
	Ui::DialogFormEmployeeClass ui;
	QMessageBox msgBox;
};

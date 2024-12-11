#pragma once

#include "ExceptionModel.h"
#include <QDialog>
#include "ui_DialogFormException.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogFormExceptionClass; };
QT_END_NAMESPACE

class DialogFormException : public QDialog
{
	Q_OBJECT

public:
	DialogFormException(QWidget* parent = nullptr);
	~DialogFormException();
	Ui::DialogFormExceptionClass* getUi();

	bool isEditMode_exception = false;
	QString idSelected = "";

signals:
	void submit(ExceptionModel exception, bool isEditMode, DialogFormException* exceptionView);

public slots:
	void onClickCancel();
	void handleSubmit();
	void setMode(bool _isEditMode);
	void setValue(ExceptionModel exception);

private:
	Ui::DialogFormExceptionClass* ui;
};

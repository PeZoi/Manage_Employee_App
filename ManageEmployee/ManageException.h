#pragma once

#include <QWidget>
#include "ui_ManageException.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ManageExceptionClass; };
QT_END_NAMESPACE

class ManageException : public QWidget
{
	Q_OBJECT

public:
	ManageException(QWidget *parent = nullptr);
	~ManageException();

	Ui::ManageExceptionClass* getUi();


signals:
	void modeEdit();

private:
	Ui::ManageExceptionClass *ui;
};

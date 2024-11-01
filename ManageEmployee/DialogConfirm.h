#pragma once

#include <QDialog>
#include "ui_DialogConfirm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogConfirmClass; };
QT_END_NAMESPACE

class DialogConfirm : public QDialog
{
	Q_OBJECT

public:
	DialogConfirm(QString content, QWidget *parent = nullptr);
	~DialogConfirm();

private:
	Ui::DialogConfirmClass *ui;
};

#pragma once

#include <QDialog>
#include "ui_DialogSettings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogSettingsClass; };
QT_END_NAMESPACE

class DialogSettings : public QDialog
{
	Q_OBJECT

public:
	DialogSettings(QWidget *parent = nullptr);
	~DialogSettings();

	Ui::DialogSettingsClass* getUi();

signals:
	void changeLanguage(QString language);

private:
	Ui::DialogSettingsClass *ui;
};

#include "DialogSettings.h"
#include "Constant.h"
#include "LanguagesUtils.h"
#include <QFile>
#include <QSettings>
#include <QPushButton>

DialogSettings::DialogSettings(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DialogSettingsClass())
{
	ui->setupUi(this);

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	QString pathIni = Constant::PATH_CONFIG;
	QFile configFile(pathIni);
	QSettings settings(pathIni, QSettings::IniFormat);

	if (settings.value("system/language").toString() == Constant::EN) {
		ui->language_list->setCurrentText("English");
	}
	else if (settings.value("system/language").toString() == Constant::VI) {
		ui->language_list->setCurrentText("Việt Nam");
	}

	connect(ui->cancelButton, &QPushButton::clicked, this, [this]() {this->accept(); });
	connect(ui->submit, &QPushButton::clicked, this, [this]() {
		QString language = ui->language_list->currentText();
		QString pathIni = Constant::PATH_CONFIG;
		QFile configFile(pathIni);
		QSettings settings(pathIni, QSettings::IniFormat);
		if (language == "English") {
			settings.setValue("system/language", Constant::EN);
			LanguagesUtils::getInstance()->switchLanguages(Constant::EN);
		}
		else {
			settings.setValue("system/language", Constant::VI);
			LanguagesUtils::getInstance()->switchLanguages(Constant::VI);

		}

		this->accept();
		});
}

DialogSettings::~DialogSettings()
{
	delete ui;
}

Ui::DialogSettingsClass* DialogSettings::getUi() {
	return ui;
}
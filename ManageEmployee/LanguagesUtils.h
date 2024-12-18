#pragma once
#include "MainWindowController.h"
#include <QTranslator>
#include <QApplication>
class LanguagesUtils
{
private:
	static LanguagesUtils* instance;
	static QTranslator* translator;
	static QApplication* app;
	static MainWindowController* mainWindowController;

	LanguagesUtils() = default;

public:
	LanguagesUtils(const LanguagesUtils&) = delete;
	LanguagesUtils& operator=(const LanguagesUtils&) = delete;
	static LanguagesUtils* getInstance() {
		if (instance == nullptr) {
			instance = new LanguagesUtils();
		}
		return instance;
	}
	void switchLanguages(QString language);
	void setAppDefault(QApplication* app, MainWindowController* mainWindowController);
};


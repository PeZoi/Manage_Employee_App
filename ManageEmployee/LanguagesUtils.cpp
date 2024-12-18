#include "LanguagesUtils.h"
#include "Constant.h"
#include <QDebug>
#include <QFile>
#include <QSettings>

LanguagesUtils* LanguagesUtils::instance = nullptr;
QApplication* LanguagesUtils::app = nullptr;
MainWindowController* LanguagesUtils::mainWindowController = nullptr;
QTranslator* LanguagesUtils::translator = new QTranslator();

void LanguagesUtils::switchLanguages(QString language) {
	if (language == Constant::VI) {

		if (translator->load(Constant::PATH_TRANSLATES_VI)) {
			app->installTranslator(translator);
		}
		else {
			qDebug() << "Failed to load language file.";
		}
	}
	else {
		app->removeTranslator(translator);
	}

	mainWindowController->getMainWindowView()->getMenu()->getUi().retranslateUi(mainWindowController->getMainWindowView()->getMenu());
	mainWindowController->getMainWindowView()->getNavbarController()->getUi()->getUi()->retranslateUi(mainWindowController->getMainWindowView()->getNavbarController()->getUi());
	mainWindowController->getEcioController()->getView()->getUi()->retranslateUi(mainWindowController->getEcioController()->getView());
	mainWindowController->getMaeController()->getView()->getUi()->retranslateUi(mainWindowController->getMaeController()->getView());
	mainWindowController->getMbController()->getMbView()->getUi()->retranslateUi(mainWindowController->getMbController()->getMbView());
	mainWindowController->getMdController()->getMdView()->getUi()->retranslateUi(mainWindowController->getMdController()->getMdView());
	mainWindowController->getMeController()->getMeView()->getUi()->retranslateUi(mainWindowController->getMeController()->getMeView());
	mainWindowController->getMexController()->getMexView()->getUi()->retranslateUi(mainWindowController->getMexController()->getMexView());
	mainWindowController->getToolsController()->getView()->getUi()->retranslateUi(mainWindowController->getToolsController()->getView());

}

void LanguagesUtils::setAppDefault(QApplication* _app, MainWindowController* _mainWindowController) {
	app = _app;
	mainWindowController = _mainWindowController;

	QString pathIni = Constant::PATH_CONFIG;
	QFile configFile(pathIni);
	QSettings settings(pathIni, QSettings::IniFormat);

	if (settings.value("system/language").toString() == Constant::VI) {
		switchLanguages(Constant::VI);
	}
}
#include "AudioUtils.h"
#include "Constant.h"
#include <QFile>
#include <QSettings>
#include <QUrl>

AudioUtils* AudioUtils::instance = nullptr;
QMediaPlayer* AudioUtils::audioWelcome = new QMediaPlayer();
QMediaPlayer* AudioUtils::audioGoodbye = new QMediaPlayer();

void AudioUtils::initAudio(){
	QString pathIni = Constant::PATH_CONFIG;
	QFile configFile(pathIni);
	QSettings settings(pathIni, QSettings::IniFormat);

	if (settings.value("system/language").toString() == Constant::EN) {
		audioWelcome->setMedia(QUrl::fromLocalFile(Constant::AUDIO_WELCOME_EN));
		audioGoodbye->setMedia(QUrl::fromLocalFile(Constant::AUDIO_GOODBYE_EN));
	}
	else if (settings.value("system/language").toString() == Constant::VI) {
		audioWelcome->setMedia(QUrl::fromLocalFile(Constant::AUDIO_WELCOME_VI));
		audioGoodbye->setMedia(QUrl::fromLocalFile(Constant::AUDIO_GOODBYE_VI));
	}
}

QMediaPlayer* AudioUtils::getAudioWelcome(){
	return audioWelcome;
}
QMediaPlayer* AudioUtils::getAudioGoodbye(){
	return audioGoodbye;
}
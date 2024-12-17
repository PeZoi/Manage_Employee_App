#pragma once
#include <QMediaPlayer>
class AudioUtils
{
private:
	static AudioUtils* instance;
	static QMediaPlayer* audioWelcome;
	static QMediaPlayer* audioGoodbye;

	AudioUtils() = default;

public:
	AudioUtils(const AudioUtils&) = delete;
	AudioUtils& operator=(const AudioUtils&) = delete;
	static AudioUtils* getInstance() {
		if (instance == nullptr) {
			instance = new AudioUtils();
		}
		return instance;
	}
	void initAudio();
	QMediaPlayer* getAudioWelcome();
	QMediaPlayer* getAudioGoodbye();
};


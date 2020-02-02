#pragma once
#include "Stuff.h"

class Audio
{
private:
	sf::Sound* sound;
	sf::SoundBuffer* soundBuffer;
	int volume;
	sf::Clock soundClock;
public:
	Audio();
	~Audio();

	void setSound(std::string filePath, int volume);
	void play();
	void play(int second);
	void setVolume(int vol);
	void setLoop(bool loop);
};


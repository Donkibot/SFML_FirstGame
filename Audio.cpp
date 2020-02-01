#include "Audio.h"



Audio::Audio()
{
	soundClock.restart();
}

Audio::~Audio()
{
	delete sound;
	delete soundBuffer;
}

void Audio::setSound(std::string filePath, int vol)
{
	this->volume = vol < 0 ? 0 : vol > 100 ? 100:vol;

	soundBuffer = new sf::SoundBuffer;
	sound = new sf::Sound;
	soundBuffer->loadFromFile(filePath);
	sound->setBuffer(*soundBuffer);
	sound->setVolume(volume);
}

void Audio::play()
{
	sound->play();
}

void Audio::play(int second)
{
	if (soundClock.getElapsedTime().asSeconds() >= second) {
		sound->play();
		soundClock.restart();
	}
}

void Audio::setVolume(int vol)
{
	this->volume = vol < 0 ? 0 : vol > 100 ? 100 : vol;
	sound->setVolume(volume);
}

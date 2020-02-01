#include "Animation.h"

Animation::Animation()
{
	frameCount = 0;
	lastframeCount = 0;
}

Animation::~Animation()
{

}

void Animation::updateAnimation(sf::Sprite& sprite, sf::IntRect* frameRect)
{
	if (animationClock.getElapsedTime().asSeconds() >= .2) {
		sprite.setTextureRect(frameRect[frameCount]);
		frameCount >= 3 ? frameCount = 0 : frameCount++;
		animationClock.restart();
	}
}

bool Animation::onceAnimation(sf::Sprite& sprite, sf::IntRect* frameRect)
{
	if (animationClock.getElapsedTime().asSeconds() >= .3) {
		sprite.setTextureRect(frameRect[lastframeCount]);
		lastframeCount++;
		animationClock.restart();
	}
	if (lastframeCount == 4)
	{
		return true;
	}
	return false;
}

void Animation::resetFrameCounter()
{
	frameCount = 0;
}





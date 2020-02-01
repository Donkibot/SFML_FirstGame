#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Animation
{
public:
	Animation();
	~Animation();
	void updateAnimation(sf::Sprite& sprite, sf::IntRect* frameRect);
	bool onceAnimation(sf::Sprite& sprite, sf::IntRect* frameRect);
	void resetFrameCounter();
	int getNumOfFrame() {
		return frameCount;
	}
	

private:
	sf::Clock animationClock;
	int frameCount;
	int lastframeCount;
};


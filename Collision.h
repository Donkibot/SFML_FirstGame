#pragma once
#include <SFML\Graphics.hpp>
#include "Stuff.h"
class Collision
{
public:
	Collision(sf::Sprite* fs) {
		firstSprite = fs;
	}

	~Collision() {
		delete firstSprite;
	}

	bool checkDotCollision(Collision& second, float firstOffset, float secondOffset) {
		secondSprite = second.getSprite();
		float firstX = firstSprite->getGlobalBounds().left;
		float firstY = firstSprite->getGlobalBounds().top;
		float firstW = firstSprite->getGlobalBounds().width;
		float firstH = firstSprite->getGlobalBounds().height;
		float secondCenterX = secondSprite->getGlobalBounds().left+ secondSprite->getGlobalBounds().width/2;
		float secondCenterY = secondSprite->getGlobalBounds().top + secondSprite->getGlobalBounds().height / 2;

		if (firstSprite->getGlobalBounds().contains(secondCenterX, secondCenterY)) {
			if (firstX + firstW / 2 < secondCenterX) {
				move(-firstOffset, 0.f, firstSprite);
				move(secondOffset, 0.f, secondSprite);
			}
				//move(-firstOffset, ((rand() % 20 -10)/ 10.f), secondOffset);
			else if (firstX + firstW / 2 > secondCenterX) {
				move(firstOffset, 0.f, firstSprite);
				move(-secondOffset, 0.f, secondSprite);
			}
				//move(firstOffset, (rand() % 20 - 10) / 10.f), secondOffset);
			if (firstY + firstH / 2 < secondCenterY) {
				move(0.f, -firstOffset, firstSprite);
				move(0.f, secondOffset, secondSprite);
			}
				//move((rand() % 20 - 10) / 10.f), -firstOffset, secondOffset);
			else if (firstY + firstH / 2 > secondCenterY) {
				move(0.f, firstOffset, firstSprite);
				move(0.f, -secondOffset, secondSprite);
			}
				//move((rand() % 20 - 10) / 10.f), firstOffset, secondOffset);
			return true;
		}
		return false;
	}

	void move(float x, float y, sf::Sprite* sprite) {
			sprite->move(x, y);
	}

	sf::Sprite* getSprite() {
		return firstSprite;
	}

private:
	sf::Sprite* firstSprite;
	sf::Sprite* secondSprite;
	bool isIntersect;
};


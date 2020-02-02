#pragma once

#include "Enemy.h"

class Creature : public Enemy
{
public:
	Creature(float x, float y) :Enemy(x, y) {
		this->initVariables();
		this->initSprite();
		this->initCollision();
		setAttackType(distance);
	}

	void move(const float dirX, const float dirY, float dt)
	{
		float xDistance = dirX - this->getPos().x;
		float yDistance = dirY - this->getPos().y;
		float distance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));
		if (distance > 200) {
			animation->updateAnimation(this->sprite, stuff->getFrameRect(liveSprites));
			float angle = atan2(yDistance, xDistance);
			float x = 0.5f * cos(angle) * movementSpeed;
			float y = 0.5f * sin(angle) * movementSpeed;
			this->sprite.move(x, y);
		}
	}

private:

	void attack(sf::Vector2f playerPos) {

	}

	void initVariables() {
		stuff = Stuff::instance();
		this->liveSprites = creatureRun;
		this->deadSprites = creatureDead;
		this->fireRate = 2.f;
		hp = hpMax = 20;
		damage = 1;
		this->animation = new Animation;
		state = Alive;
		this->movementSpeed = 1.2f;
	}
};


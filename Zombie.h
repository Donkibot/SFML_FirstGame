#pragma once
#include "Enemy.h"

class Zombie : public Enemy
{
public:
	Zombie(float x, float y) :Enemy(x, y) {
		this->initVariables();
		this->initSprite();
		this->initCollision();
		setAttackType(melee);
	}

	void move(const float dirX, const float dirY, float dt)
	{
		animation->updateAnimation(this->sprite, stuff->getFrameRect(liveSprites));

		float angle = atan2(dirY - this->getPos().y, dirX - this->getPos().x);
		float x = 0.5f * cos(angle) * movementSpeed;
		float y = 0.5f * sin(angle) * movementSpeed;
		this->sprite.move(x, y);
	}

	void attack(sf::Vector2f playerPos) {

	}

private:

	void initVariables() {
		stuff = Stuff::instance();
		this->liveSprites = zombieRun;
		this->deadSprites = zombieDead;
		this->fireRate = 2.f;
		hp = hpMax = 20;
		damage = 1;
		this->animation = new Animation;
		state = Alive;
		this->movementSpeed = 2.1f;
	}

};


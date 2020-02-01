#include "Enemy.h"

Enemy::Enemy(float x, float y)
{
	this->setPosition(x, y);
	
	std::cout << "Enemy was called\n";
}


//void Enemy::move(const float dirX, const float dirY, float dt)
//{
//	animation->updateAnimation(this->sprite, stuff->getFrameRect(liveSprites));
//	
//	float angle = atan2(dirY - this->getPos().y, dirX - this->getPos().x);
//	float x = 0.5f * cos(angle) * movementSpeed;
//	float y = 0.5f * sin(angle) * movementSpeed;
//	this->sprite.move(x, y);
//}

//
//void Enemy::initVariables() {
//	stuff = Stuff::instance();
//	this->liveSprites = dogRun;
//	this->deadSprites = zombieDead;
//	this->fireRate = 2.f;
//	hp = hpMax = 20;
//	damage = 4;
//	this->animation = new Animation;
//	state = Alive;
//	this->movementSpeed = 1.2f;
//}

Enemy::~Enemy()
{
	
}
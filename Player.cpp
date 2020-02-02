#include "Player.h"


Player::Player()
{
	this->initVariables();
	this->initSprite();
	this->initCollision();
}

Player::~Player()
{
	
}

void Player::initVariables() {
	liveSprites = playerRun;
	deadSprites = playerDead;
	fireRate = 0.3f;
	hp = hpMax = 20;
	damage = 5;
	animation = new Animation;
	state = Alive;
	movementSpeed = 2.0f;
	stuff = Stuff::instance();
}

bool Player::hasMadeOneStep()
{
	static int callTimes = 0;
	if (animation->getNumOfFrame() == 0 || animation->getNumOfFrame() == 2) {
		if (callTimes == 0)
		{
			callTimes++;
			return true;
		}
	}
	else callTimes = 0;
	return false;
}

void Player::attack(int& hp)
{
	hp -= this->damage;
	std::cout << hp << std::endl;
}



void Player::move(const float dirX, const float dirY, float dt)
{
	if(isAlive())
	animation->updateAnimation(this->sprite, stuff->getFrameRect(liveSprites));
	float xMove = this->movementSpeed * dirX * dt * 60.f;
	float yMove = this->movementSpeed * dirY * dt * 60.f;
	this->sprite.move(xMove, yMove);
}

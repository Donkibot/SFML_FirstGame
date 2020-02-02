#include "Enemy.h"

Enemy::Enemy(float x, float y)
{
	this->setPosition(x, y);
	
	std::cout << "Enemy was called\n";
}


Enemy::~Enemy()
{
	
}
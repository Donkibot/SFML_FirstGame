#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(enum source src,sf::Texture* texture, float posX, float posY, float dirX, float dirY, float moveSpeed)
{
	float angle = atan2(dirY - posY, dirX - posX);
	float x = cos(angle);
	float y = sin(angle);
	this->shape.setTexture(*texture);
	this->shape.setScale(0.4f,0.4f);
	this->shape.setPosition(posX+x*30,posY+y*30);
	this->shape.setOrigin(7, 7);
	this->direction = sf::Vector2f(x,y);
	this->moveSpeed = moveSpeed;
	initCollision();
	setSource(src);
}

Bullet::~Bullet()
{
}

sf::FloatRect Bullet::getBound()
{
	return this->shape.getGlobalBounds();
}

void Bullet::update(float dt)
{
	//this->shape.move(this->moveSpeed*this->direction*dt*60.f);
	this->shape.move(this->moveSpeed*this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

Collision& Bullet::getCollision()
{
		return *collision;
}

source Bullet::getSource()
{
	return source;
}

void Bullet::setSource(enum source s)
{
	this->source = s;
}

void Bullet::initCollision()
{
		collision = new Collision(&this->shape);
}

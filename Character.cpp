#include "Character.h"

void Character::initSprite()
{
	this->sprite.setTexture(*this->stuff->getCharacterTexture());
	sprite.setTextureRect(stuff->getFrameRect(liveSprites)[0]);
	sprite.setOrigin(112 / 2, 112 / 2);
	sprite.setScale(0.5f, 0.5f);
}

void Character::initCollision()
{
	collision = new Collision(&this->sprite);
}


Character::~Character()
{
	delete animation;
}


void Character::dyingProcess()
{
	if (animation->onceAnimation(this->sprite, stuff->getFrameRect(deadSprites))) {
		state = Dead;
	}
}

State Character::getState()
{
	return state;
}

bool Character::isAlive()
{
	return state == Alive;
}

bool Character::canAttack()
{
	if (attackTime.getElapsedTime().asSeconds() >= fireRate && isAlive()) {
		attackTime.restart();
		return true;
	}
	return false;
}

int& Character::getHp()
{
	return hp;
}

void Character::attack(int& hp)
{
	if (canAttack()) {
		hp -= this->damage;
		std::cout << hp << std::endl;
	}
}


Collision& Character::getCollision() {
	return *collision;
}

void Character::setPosition(float posX, float posY)
{
	this->sprite.setPosition(posX, posY);
}


void Character::rotate(sf::Vector2i mousePos)
{
	sf::Vector2f heroPos = sprite.getPosition();
	float dx = mousePos.x - heroPos.x;
	float dy = mousePos.y - heroPos.y;
	float PI = atan(1) * 4;
	float angle = atan2(dy, dx);
	sprite.setRotation(angle * 180 / PI);
}


void Character::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

void Character::update()
{
	if (hp <= 0 && state != Dead) {
		state = Dying;
	}
}

sf::Vector2f Character::getPos()
{
	return this->sprite.getPosition();
}


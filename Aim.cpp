#include "Aim.h"

Aim::Aim(sf::Texture* texture)
{
	this->aimSprite.setTexture(*texture);
	this->aimSprite.setScale(0.1f,0.1f);
	this->aimSprite.setOrigin(100.f,100.f);
}

Aim::~Aim()
{
}

void Aim::update(sf::Vector2f position)
{
	this->aimSprite.setPosition(position);
}

void Aim::render(sf::RenderTarget* target)
{
	target->draw(aimSprite);
}

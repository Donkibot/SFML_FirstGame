#pragma once
#include "Stuff.h"

class Aim 
{
public:
	Aim(sf::Texture* texture);
	~Aim();

	void update(sf::Vector2f position);
	void render(sf::RenderTarget* target);

private:
	sf::Sprite aimSprite;

};


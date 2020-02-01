#pragma once
#include "Stuff.h"

enum source {
	plr,
	enm
};

class Bullet
{
public:
	Bullet();
	Bullet(enum source src, sf::Texture* texture, float posX, float posY, float dirX, float dirY, float moveSpeed);
	~Bullet();

	sf::FloatRect getBound();

	void update(float dt);
	void render(sf::RenderTarget* target);
	Collision& getCollision();
	source getSource();
	void setSource(enum source s);

private:
	sf::Sprite shape;
	sf::Vector2f direction;
	float moveSpeed;
	Collision* collision;
	enum source source;

	void initCollision();
};


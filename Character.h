#pragma once
#include "Stuff.h"

enum State {
	Alive,
	Dying,
	Dead
};

class Character
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock attackTime;

	float fireRate;
	float movementSpeed;
	int hp;
	int hpMax;
	int damage;

	State state;
	Stuff* stuff;
	Animation* animation;
	Collision* collision;

	characters liveSprites;
	characters deadSprites;


	void initSprite();
	virtual void initVariables()=0;
	void initCollision();

public:
	virtual ~Character();

	void dyingProcess();
	State getState();
	bool isAlive();
	virtual bool canAttack();
	int& getHp();
	void attack(int& hp);
	Collision& getCollision();
	void setPosition(float posX, float posY);
	virtual void move(const float dirX, const float dirY, float dt) = 0;
	void rotate(sf::Vector2i mousePos);
	virtual void update();
	void render(sf::RenderTarget* target);
	sf::Vector2f getPos();
};


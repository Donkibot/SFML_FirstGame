#pragma once
#include "Character.h"


class Player: public Character
{
private:
	void initVariables();

public:
	Player();
	~Player();



	void move(const float dirX, const float dirY, float dt);
	bool hasMadeOneStep();
	void attack(int& hp);
};


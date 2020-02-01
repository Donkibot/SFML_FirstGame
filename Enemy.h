#pragma once
#include "Character.h"

enum attackType {
	melee,
	distance
};

class Enemy: public Character
{
public:
	Enemy(float x, float y);
	~Enemy();

	enum attackType getAttackType() {
		return attacktype;
	}
	void setAttackType(enum attackType at) {
		attacktype = at;
	}

	virtual void move(const float dirX, const float dirY, float dt)=0;

protected:
	virtual void initVariables()=0;
	enum attackType attacktype;

};


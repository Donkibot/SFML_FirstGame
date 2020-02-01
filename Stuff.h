#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Collision.h"

enum characters {
	playerRun,
	playerRun1,
	playerDead,
	playerRun3,
	zombieRun,
	zombieRun1,
	zombieDead,
	zombieDead1,
	dogRun,
	creatureRun,
	dogDead,
	creatureDead
};


class Stuff
{
public:
	Stuff();
	static Stuff* instance();
	~Stuff();
	void initTextures();
	sf::Texture* getTexture(std::string textureName);
	void initFrameRect(float frameWidth, float frameHeight);
	sf::IntRect* getFrameRect(enum characters person);
	sf::Texture* getCharacterTexture();

private:
	sf::IntRect** frameRect;
	sf::Texture** textureSet;
	sf::Texture* characterTexture;
	std::map<std::string, sf::Texture*> textures;
};

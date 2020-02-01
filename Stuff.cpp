#include "Stuff.h"


Stuff::Stuff()
{
	characterTexture = new sf::Texture;
}

Stuff* Stuff::instance()
{
	static Stuff* stf = new Stuff();

	return stf;
}

Stuff::~Stuff()
{
	delete characterTexture;
}

void Stuff::initTextures()
{
	if (!this->characterTexture->loadFromFile("Images/sprite.png"))
	{
		std::cout << "ERROR::PLAYER::INIT_TEXTURE" << std::endl;
	}
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Images/bullet1.png");

	this->textures["AIM"] = new sf::Texture();
	this->textures["AIM"]->loadFromFile("Images/aim.png");

	this->textures["BackGround"] = new sf::Texture();
	this->textures["BackGround"]->loadFromFile("Images/background.jpg");

}

sf::Texture* Stuff::getTexture(std::string textureName)
{
	return textures[textureName];
}

void Stuff::initFrameRect(float frameWidth, float frameHeight)
{
	sf::IntRect frameSize = sf::IntRect(0, 0, frameWidth, frameHeight);

	frameRect = new sf::IntRect * [12];

	for (int i = 0; i < 12; i++)
	{
		frameRect[i] = new sf::IntRect[4];
		for (int j = 0; j < 4; j++)
		{
			frameRect[i][j] = frameSize;
			frameSize.left += frameWidth;
		}
		if (i % 2 != 0) {
			frameSize.left = 0;
			frameSize.top += frameHeight;
		}
	}
}

sf::IntRect* Stuff::getFrameRect(enum characters person)
{
	return frameRect[person];
}

sf::Texture* Stuff::getCharacterTexture()
{
	return characterTexture;
}
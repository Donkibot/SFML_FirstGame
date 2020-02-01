#pragma once
#include "Stuff.h"

class Text_Information
{
public:
	Text_Information(sf::Vector2f pos, std::string text);

	void initFont();



	/*Text_Information(sf::Vector2f pos, std::string text) {
		initFont("asd");
	}

	void initFont(std::string fontPath) {
		if (this->font.loadFromFile(fontPath)) {
			std::cout << "Font loading error. Path: " + fontPath << std::endl;
		}
		this->font = font;
	}*/


private:

	sf::Font font;
};


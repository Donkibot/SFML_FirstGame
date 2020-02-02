#include "Text_Information.h"

void Text_Information::initFont(std::string fontPath)
{
	if (!this->font.loadFromFile(fontPath)) {
		std::cout << "Font loading error. Path: " + fontPath << std::endl;
	}
	this->text.setFont(font);
}

void Text_Information::setString(std::string string)
{
	text.setString(string);
}

void Text_Information::setPosition(sf::Vector2f position)
{
	text.setPosition(position);
}

void Text_Information::setCenterPosition(sf::Vector2f position)
{
	sf::FloatRect bounds = text.getGlobalBounds();
	text.setOrigin(bounds.width/2,bounds.height/2);
	text.setPosition(position);
}

void Text_Information::setColor(sf::Color color)
{
	text.setFillColor(color);
}

void Text_Information::setScale(sf::Vector2f scale)
{
	text.setScale(scale);
}

void Text_Information::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->text);
}

#pragma once
#include "Stuff.h"

class Text_Information : public sf::Drawable
{
public:
	void initFont(std::string fontPath);
	void setString(std::string string);
	void setPosition(sf::Vector2f position);
	void setCenterPosition(sf::Vector2f position);
	void setColor(sf::Color color);
	void setScale(sf::Vector2f scale);


private:
	sf::Text text;
	sf::Font font;

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


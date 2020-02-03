#pragma once
#include <SFML\Graphics.hpp>
#include "Text_Information.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	void initBackground(sf::RectangleShape*& rect, sf::Texture* texture);
	void loadTexture(sf::Texture*& texture,std::string path);

	void setBackgroundSize(float width, float height);
	void setBackgroundPos(float x, float y);

	void setInfRectSize(float width, float height);
	void setInfRectPos(float x, float y);

	int getSelectedItem();
	void setPressedItem(int item);
	int getPressedItem();
	void setVisible(bool visible);
	bool getVisible();

private:
	bool visible;
	int selectedItem;
	int pressedItem;
	sf::Font font;
	Text_Information menu[MAX_NUMBER_OF_ITEMS];
	sf::Texture* backTexture;
	sf::Texture* aboutGame;
	sf::RectangleShape* backGround;
	sf::RectangleShape* informationRectangle;
};


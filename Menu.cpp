#include "Menu.h"

Menu::Menu(float width, float height)
{
	loadTexture("Images/menuBG.jpg");
	initBackground();

	menu[0].initFont("Fonts/ENGR.TTF");
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setCenterPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*1));

	menu[1].initFont("Fonts/ENGR.TTF");
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Option");
	menu[1].setCenterPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*2));

	menu[2].initFont("Fonts/ENGR.TTF");
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setCenterPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*3));

	selectedItem = 0;
	pressedItem = 5;
	visible = true;
}

Menu::~Menu()
{
	delete texture;
	delete backGround;
}

void Menu::draw(sf::RenderWindow& window)
{
	if (visible) {
		window.draw(*backGround);
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
			window.draw(menu[i]);
		}
	}
}

void Menu::MoveUp()
{
	if (selectedItem-1 >=0)
	{
		menu[selectedItem].setColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItem+1 < 3)
	{
		menu[selectedItem].setColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setColor(sf::Color::Red);
	}
}

void Menu::initBackground()
{
	backGround = new sf::RectangleShape;
	backGround->setSize(sf::Vector2f(600,600));
	backGround->setTexture(texture);
}

void Menu::loadTexture(std::string path)
{
	texture = new sf::Texture;
	texture->loadFromFile(path);
}

void Menu::setBackgroundSize(float width, float height)
{
	backGround->setSize(sf::Vector2f(width, height));
}

void Menu::setBackgroundPos(float x, float y)
{
	backGround->setPosition(x,y);

}

int Menu::getSelectedItem()
{
	return selectedItem;
}

void Menu::setPressedItem(int item)
{
	pressedItem = selectedItem;
}

int Menu::getPressedItem()
{
	return pressedItem;
}

void Menu::setVisible(bool visible)
{
	this->visible = visible;
}

bool Menu::getVisible()
{
	return visible;
}



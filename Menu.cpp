#include "Menu.h"

Menu::Menu(float width, float height)
{
	loadTexture(backTexture, "Images/menuBG.jpg");
	loadTexture(aboutGame, "Images/menuAbout.jpg");
	initBackground(informationRectangle, aboutGame);
	initBackground(backGround, backTexture);

	menu[0].initFont("Fonts/ENGR.TTF");
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setCenterPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*1));

	menu[1].initFont("Fonts/ENGR.TTF");
	menu[1].setColor(sf::Color::White);
	menu[1].setString("About Game");
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
	delete backTexture;
	delete aboutGame;
	delete backGround;
}

void Menu::draw(sf::RenderWindow& window)
{
	if (visible) {
		window.draw(*backGround);
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
			window.draw(menu[i]);
		}
		if (pressedItem == 1) {
			window.draw(*informationRectangle);
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

void Menu::initBackground(sf::RectangleShape*& rect, sf::Texture* texture)
{
	rect = new sf::RectangleShape;
	rect->setSize(sf::Vector2f(600, 600));
	rect->setTexture(texture);
}

void Menu::loadTexture(sf::Texture*& texture, std::string path)
{
	texture = new sf::Texture;
	if (!texture->loadFromFile(path)) {
		std::cout << "Load image error. Menu.cpp loadTexture" << std::endl;
	}
}

void Menu::setBackgroundSize(float width, float height)
{
	backGround->setSize(sf::Vector2f(width, height));
}

void Menu::setBackgroundPos(float x, float y)
{
	backGround->setPosition(x,y);
}

void Menu::setInfRectSize(float width, float height)
{
	informationRectangle->setSize(sf::Vector2f(width, height));
}

void Menu::setInfRectPos(float x, float y)
{
	informationRectangle->setPosition(x, y);
}

int Menu::getSelectedItem()
{
	return selectedItem;
}

void Menu::setPressedItem(int item)
{
	pressedItem = item;
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



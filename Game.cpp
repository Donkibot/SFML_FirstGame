#include "Game.h"

Game::Game()
{
	initVariables();
	initWindow();
	initStuff();
	initBackGround();
	initSound();
	initAim();
	initEnemies();
	initPlayer();
	initCamera();
	initMenu();
	initText();
}

void Game::upadateEvents()
{
	while (this->window->pollEvent(this->evnt)) {
		switch (this->evnt.type) {
		case (sf::Event::Closed): this->window->close(); break;
		case(sf::Event::Resized): {
			sf::FloatRect visibleArea(0, 0, evnt.size.width, evnt.size.height);
			view->setSize(evnt.size.width, evnt.size.height);
			break;
		}
		case sf::Event::KeyReleased:
			switch (evnt.key.code)
			{
			case sf::Keyboard::W: if(menu->getPressedItem()!=1) menu->MoveUp(); break;
			case sf::Keyboard::S: if (menu->getPressedItem() != 1) menu->MoveDown(); break;
			case sf::Keyboard::Return: {
				if (menu->getVisible()) {
					menu->setPressedItem(menu->getSelectedItem());
					switch (menu->getSelectedItem()) {
					case 0: {
						gameStatus = 0; 
						menu->setVisible(false); 
						audio["BG_MUSIC"]->play();
						break; 
					}
						case 1: break;
						case 2: this->window->close(); break;
					}
				}
				break; 
			}
			case sf::Keyboard::Escape: {
				if (menu->getPressedItem() != 1) {
					menu->setVisible(!menu->getVisible());
					if (menu->getVisible()) {
						gameStatus = 5;
						audio["BG_MUSIC"]->pause();
					}
					else {
						gameStatus = 0;
						audio["BG_MUSIC"]->play();
					}
				}
				else {
					menu->setPressedItem(5);
				}
			}
			default:
				break;
			}

		}
	}
}

void Game::update()
{
	updateDt();
	updateFPS();
	upadateEvents();
	if (gameStatus == 0) {
		updateBullets();
		updateInput();
		updatePlayer();
		spawnEnemies();
		updateEnemies();
		updateText();
		updateCollision();
		updateCamera();
	}
}

void Game::updateInput()
{
	sf::Vector2i mousePosRelativeToWindow = sf::Mouse::getPosition(*this->window);
	sf::Vector2f mousePos = window->mapPixelToCoords(mousePosRelativeToWindow);
	if (player->isAlive()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			if (player->hasMadeOneStep()) audio["FOOTSTEP"]->play();
			this->player->move(-1.f, 0.f, dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			if (player->hasMadeOneStep()) audio["FOOTSTEP"]->play();
			this->player->move(1.f, 0.f, dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			if (player->hasMadeOneStep()) audio["FOOTSTEP"]->play();
			this->player->move(0.f, -1.f, dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			if (player->hasMadeOneStep()) audio["FOOTSTEP"]->play();
			this->player->move(0.f, 1.f, dt);
		}

		player->rotate((sf::Vector2i)mousePos);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
		{
			audio["SHOOT"]->play();
			this->bullets.push_back(new Bullet(plr, stuff->getTexture("BULLET"), this->player->getPos().x, this->player->getPos().y, mousePos.x, mousePos.y, 50.f));
		}

	}
	this->aim->update(sf::Vector2f(mousePos.x, mousePos.y));
}

void Game::updateCamera()
{
	//camera.setViewCoord(player->getPos().x, player->getPos().y);
	windowTop = window->mapPixelToCoords(sf::Vector2i(0, 0)).y;
	windowDown = window->mapPixelToCoords(sf::Vector2i(0, view->getSize().y)).y;
	windowLeft = window->mapPixelToCoords(sf::Vector2i(0, 0)).x;
	windowRight = window->mapPixelToCoords(sf::Vector2i(view->getSize().x, 0)).x;
}


void Game::updatePlayer()
{
	player->update();
	if (player->getState() == Dying) {
		player->dyingProcess();
		audio["PLAYER_DEAD"]->play(2);

	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* b : bullets) {
		b->update(dt);

		//���� ������ �� ������ ���� �������� ����
		if (b->getBound().top + b->getBound().height < windowTop) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			counter--;
		}
		//���� ������ �� ����� �������� ����
		else if (b->getBound().top > windowDown) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			counter--;
		}
		//���� ������ �� ��� ���� �������� ����
		else if (b->getBound().left + b->getBound().width < windowLeft) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			counter--;
		}
		//���� ������ �� ����� ���� �������� ����
		else if (b->getBound().left > windowRight) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			counter--;
		}
		counter++;
	}
}

void Game::updateCollision()
{
	int counter = 0;
	int bulletCount = 0;
	for (auto* enemy : enemies) {
		if (enemy->isAlive()) {
			if (enemy->getCollision().checkDotCollision(player->getCollision(), 2.f, 0.f)) {
				enemy->attack(player->getHp());
			}

			for (int i = 0; i < enemies.size(); i++) {
				if (counter == i) continue;
				if (enemies.at(i)->isAlive())
					enemy->getCollision().checkDotCollision(enemies.at(i)->getCollision(), 2.f, 0.f);
			}
		}
		if (enemy->isAlive()) {
			for (auto bullet : bullets) {
				if (bullet->getSource() == plr) {
					if (enemy->getCollision().checkDotCollision(bullet->getCollision(), 5.f, 0.f)) {
						this->player->attack(enemy->getHp());
						delete bullets.at(bulletCount);
						bullets.erase(bullets.begin() + bulletCount);
						audio["ENEMY_HIT"]->play(4);
						bulletCount--;
					}
					bulletCount++;
				}
			}
		}
		bulletCount = 0;
		counter++;
	}
	bulletCount = 0;
	for (auto bullet : bullets) {
		if (bullet->getSource() == enm) {
			if (this->player->getCollision().checkDotCollision(bullet->getCollision(), 0.f, 0.f)) {
				this->player->getHp() -= 1;
				delete bullets.at(bulletCount);
				bullets.erase(bullets.begin() + bulletCount);
				bulletCount--;
			}
			bulletCount++;
		}
	}
}

void Game::updateText()
{
	lifeText->setString("Life: " + std::to_string(player->getHp()));

	scoreText->setString("Score: " + std::to_string(score));
}

void Game::spawnEnemies()
{
	float spawnAngle = (rand() % 360) * (3.14 / 180);
	float xSpawn = view->getCenter().x + cos(spawnAngle) * view->getSize().x;
	float ySpawn = view->getCenter().y + sin(spawnAngle) * view->getSize().x;

	if (enemyClock.getElapsedTime().asSeconds() > 1.5f && numOfEnemies < maxNumOfEnemies) {
		if (numOfEnemies % 5 == 4) {
			this->enemies.push_back(new Creature(xSpawn, ySpawn));
		}
		else
			this->enemies.push_back(new Zombie(xSpawn, ySpawn));
		numOfEnemies++;
		enemyClock.restart();
	}
}

void Game::initText()
{
	lifeText = new Text_Information();
	scoreText = new Text_Information();
	endText = new Text_Information();

	lifeText->initFont("Fonts/ENGR.TTF");
	scoreText->initFont("Fonts/ENGR.TTF");
	endText->initFont("Fonts/ENGR.TTF");

	lifeText->setString("Life: ");
	scoreText->setString("Score: " + std::to_string(windowLeft));
	endText->setString("YOU DIED");

	lifeText->setPosition(sf::Vector2f(windowLeft, windowTop));
	scoreText->setPosition(sf::Vector2f(windowLeft + 300, windowTop));
	endText->setCenterPosition(window->mapPixelToCoords((sf::Vector2i)view->getCenter()));

	endText->setScale(sf::Vector2f(3, 3));
	endText->setColor(sf::Color::Red);

}

void Game::updateEnemies()
{
	int counter = 0;
	for (auto enemy : enemies) {
		enemy->update();
		if (enemy->getState() == Alive) {
			enemy->move(player->getPos().x, player->getPos().y, dt);
			enemy->rotate((sf::Vector2i)player->getPos());
			if (enemy->getAttackType() == distance)
			{
				if (enemy->canAttack()) {
					audio["SHOOT"]->play();
					this->bullets.push_back(new Bullet(enm, stuff->getTexture("BULLET"), enemy->getPos().x, enemy->getPos().y, player->getPos().x, player->getPos().y, 4.f));
				}
			}
		}
		if (enemy->getState() == Dying) {
			enemy->dyingProcess();
			audio["ENEMY_HIT"]->play(2);
			if (enemy->getState() == Dead) {
				score++;
			}
		}
		counter++;
	}
}

void Game::render()
{
	//������ ������� ��'����

	this->window->clear(sf::Color(100, 0, 155));
	//-----------------------------------------------//

	window->draw(backGround);

	for (auto* b : bullets) {
		b->render(this->window);
	}

	for (auto enemy : enemies) {
		if (!enemy->isAlive())
			enemy->render(this->window);
	}

	this->player->render(this->window);

	for (auto enemy : enemies) {
		if (enemy->isAlive())
			enemy->render(this->window);
	}

	this->aim->render(this->window);
	window->draw(*lifeText);
	window->draw(*scoreText);
	if (player->getState() == Dead)
		window->draw(*endText);

	menu->draw(*window);
	//-----------------------------------------------//
	this->window->display();
}

void Game::run()
{
	while (window->isOpen()) {
		update();
		render();
	}
}

void Game::updateDt()
{
	this->dt = dtClock.restart().asSeconds();
}

void Game::updateFPS()
{
	float currTime = fpsClock.getElapsedTime().asSeconds();
	fps = 1 / (currTime - lastFPSTime);
	lastFPSTime = currTime;
	//std::cout << "Fps = " << fps << std::endl;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(this->videoMode, title);
	this->window->setFramerateLimit(this->framerate_limit);
	this->window->setVerticalSyncEnabled(this->vertical_sync_enabled);
	this->window->setMouseCursorVisible(false);
}

void Game::initMenu()
{
	menu = new Menu(videoMode.width, videoMode.height);
	menu->setBackgroundSize(window->getSize().x*1.6, window->getSize().y*1.6);
	menu->setBackgroundPos(-200, -200);
	menu->setInfRectSize(window->getSize().x*1.6, window->getSize().y*1.6);
	menu->setInfRectPos(-200, -200);

}

void Game::initCamera()
{
	view = camera.getView();
	view->reset(sf::FloatRect(0, 0, videoMode.width, videoMode.height));
	view->zoom(1.5);
	window->setView(*view);
	windowTop = window->mapPixelToCoords(sf::Vector2i(0, 0)).y;
	windowDown = window->mapPixelToCoords(sf::Vector2i(0, view->getSize().y)).y;
	windowLeft = window->mapPixelToCoords(sf::Vector2i(0, 0)).x;
	windowRight = window->mapPixelToCoords(sf::Vector2i(view->getSize().x, 0)).x;
}


void Game::initBackGround()
{
	backGround.setTexture(*stuff->getTexture("BackGround"));
	backGround.scale(1.6, 1.6);
	backGround.move(-600, -240);
}

void Game::initVariables()
{
	this->window = nullptr;
	std::ifstream ifs("Config/window.ini");
	this->title = "None";
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->framerate_limit = 120;
	this->vertical_sync_enabled = false;

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> videoMode.width >> videoMode.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}
	ifs.close();

	numOfEnemies = 0;
	maxNumOfEnemies = 100;
	gameStatus = 5;
}

void Game::initPlayer()
{
	player = new Player();
	player->setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2);
}

void Game::initAim()
{
	this->aim = new Aim(this->stuff->getTexture("AIM"));
}

void Game::initSound()
{
	//���� �������
	audio["SHOOT"] = new Audio;
	audio["SHOOT"]->setSound("Sounds/pistol.wav", 40);

	//���� ����
	audio["FOOTSTEP"] = new Audio;
	audio["FOOTSTEP"]->setSound("Sounds/footstep.ogg", 70);

	//������� ������
	audio["ENEMY_HIT"] = new Audio;
	audio["ENEMY_HIT"]->setSound("Sounds/zombieHurt.wav", 70);

	//������� ������
	audio["PLAYER_DEAD"] = new Audio;
	audio["PLAYER_DEAD"]->setSound("Sounds/playerDead.wav", 70);

	//������ ������
	audio["BG_MUSIC"] = new Audio;
	audio["BG_MUSIC"]->setSound("Sounds/bgMusic.ogg", 70);
	audio["BG_MUSIC"]->setLoop(true);
	
}

void Game::initStuff()
{
	this->stuff = Stuff::instance();
	this->stuff->initTextures();
	this->stuff->initFrameRect(113, 113);
}

void Game::initEnemies()
{
	maxNumOfEnemies = 200;
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->stuff;
	//�������� ��� � ���'��
	for (auto* b : this->bullets) {
		delete b;
	}

	//�������� �������� ����� � ���'��
	for (auto s : audio) {
		delete s.second;
	}
}

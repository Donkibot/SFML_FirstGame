#pragma once

#include <map>
#include <fstream>
#include "Player.h"
#include "Bullet.h"
#include "Aim.h"
#include "Stuff.h"
#include "Audio.h"
#include "Enemy.h"
#include "Zombie.h"
#include "Creature.h"
#include "Camera.h"
#include "level.h"

/*
    Клас, що відповідальний за ігровий процес
*/
class Game
{
public:
    //Конструктор та деструктор
    Game();
    virtual ~Game();

    //Функції
    
    void run();
    


private:
    //Змінні
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    std::string title;
    sf::Event evnt;
    sf::Clock dtClock;
    sf::Clock fpsClock;

    float lastFPSTime = 0;
    float dt;
    int fps;
    unsigned framerate_limit;
    bool vertical_sync_enabled;

    Player* player;
    Aim* aim;
    Stuff* stuff;

    //Ресурси
    std::map<std::string, Audio*> audio;
    std::vector<Bullet*> bullets;
    sf::Sprite backGround;
    //Вороги
    std::vector<Enemy*> enemies;
    int numOfEnemies;
    int maxNumOfEnemies;
    sf::Clock enemyClock;

    //Камера
    Camera camera;
    sf::View* view;
    int windowTop;
    int windowDown;
    int windowLeft;
    int windowRight;

    //Мапа рівня
    //Level lvl;


    //Приватній функції
    void initWindow();
    void initCamera();
    void initLevel();
    void initBackGround();
    void initVariables();
    void initPlayer();
    void initAim();
    void initSound();
    void initStuff();
    void initEnemies();
    void upadateEvents();
    void render();
    void spawnEnemies();

    void update();
    void updateDt(); 
    void updateFPS();
    void updateInput();
    void updateCamera();
    void updateWindow();
    void updatePlayer();
    void updateEnemies();
    void updateBullets();
    void updateCollision();

};


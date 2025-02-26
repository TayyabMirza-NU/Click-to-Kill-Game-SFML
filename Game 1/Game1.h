#pragma once

#include<iostream>
#include<vector>
#include<ctime>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;


class Game1 {
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videomode;

    // Mouse Position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Game Logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
   



    //Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;


    //privete functions
    void initvariables();
    void initWindow();
    void initEnemies();

public:
    // Constructor/ Destructor
    Game1();
    ~Game1();


    // Accessor
    const bool running() const;


    // Functions

    void pollEvents();
    void spawnEnemies();

    void updateMousePositions();
    void updateEnemies();
    void update();

    void renderEnemies();
    void render();
};

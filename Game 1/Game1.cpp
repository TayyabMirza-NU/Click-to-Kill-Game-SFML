#include "Game1.h"

// Private Functions

void Game1::initvariables()
{
	this->window = nullptr;

	// Game Logic
	this->points = 0;
	this->enemySpawnTimerMax = 50.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;


}

void Game1::initWindow()
{
	this->videomode.height = 640;
	this->videomode.width = 960;
	this->window = new sf::RenderWindow(this->videomode, "Shooting Game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);	
}

void Game1::initEnemies()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

// Constructors / Destructors

Game1::Game1()
{
	this->initvariables();
	this->initWindow();
	this->initEnemies();
}

Game1::~Game1()
{
	delete this->window;
}


// Accessors

const bool Game1::running() const
{
	return this->window->isOpen();
}

// Functions

void Game1::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {
		if (this->ev.type == sf::Event::Closed)
			this->window->close();

		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if(this->ev.key.code == sf::Keyboard:: Escape)
			this->window->close();
			break;
		}
	}

}

void Game1::spawnEnemies()
{

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x-this->enemy.getSize().x)),0.f);

	this->enemy.setFillColor(sf::Color::Green);

	// Spawn the Enemy
	this->enemies.push_back(this->enemy);
}

void Game1::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

}



void Game1::updateEnemies()
{
	// updating the timer for enemy spawning
	if (this->enemies.size()< this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			//spawn the enemy and reset timer
			this->spawnEnemies();
			this->enemySpawnTimer = 0.f;
		}
		else 
			this->enemySpawnTimer += 1.f;
	}


	// Move the Enemy
	for (int i = 0; i < enemies.size();i++) {
		bool deleted = false;

		this->enemies[i].move(0.f, 5.f);

		// Check if clicked upon  
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) 
			{
				deleted = true;
			}
		}


		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			deleted = true;
		}

		if (deleted) {
			this->enemies.erase(this->enemies.begin() + i);
		}

	}



}



void Game1::update()
{
	this->pollEvents();

	this->updateMousePositions();

	this->updateEnemies();
}
 


void Game1::renderEnemies()
{
	for (auto& e : this->enemies) {
		this->window->draw(e);
	}
}

void Game1::render()
{
	this->window->clear(); // Clear the window

	// Render objects here
	this->renderEnemies();

	this->window->display();
}

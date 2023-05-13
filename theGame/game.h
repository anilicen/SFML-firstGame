#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#pragma once
class game
{
private:
	//windows 
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::ContextSettings settings;

	//game logic 
	bool endGame;
	unsigned int points;
	unsigned int lives;
	unsigned int missileCounter;
	unsigned int maxMissileCounter;
	bool keys[4] = { false }; //fix


	std::vector<sf::RectangleShape> missiles;
	sf::RectangleShape missile;

	sf::RectangleShape player;

	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initMissile();
	void initPlayer();


public:
	//Constructors / Destructors
	game();
	virtual ~game();

	//accessors
	const bool running() const;
	const bool getEndGame() const;

	//game functions

	void isPlayerHit();
	void coinCollect();
	void updateCoins();
	void updateScore();
	void pollEvents();
	void updateMissilePosition();
	void update();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void movePlayer();

	void renderText(sf::RenderTarget& target);
	void renderPlayer(sf::RenderTarget& target);
	void render();


};


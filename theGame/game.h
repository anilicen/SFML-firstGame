#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include<sstream>

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
	sf::Texture texture;
	sf::Sprite background;
	sf::Text pointsText;
	sf::Text livesText;

	sf::Text endGameText;

	sf::Font font;
	//game logic 
	bool endGame;
	unsigned int points;
	unsigned int lives;
	unsigned int missileCounter;
	unsigned int maxMissileCounter;
	unsigned int randomMissileSpawn;
	unsigned int randomMissileSpawnMax;

	int backgroundCounter;
	bool keys[4];//fix


	std::vector<sf::ConvexShape> missiles;
	sf::ConvexShape missile;

	sf::RectangleShape player;

	void initVariables();
	void initWindow();
	void initFonts();
	void initBackground();
	void initText();
	void initMissile();
	void initPlayer();

	void initEndGameText();

	void moveBackground();
	void spawnMissile();

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
	void updateText();
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
	void renderMissile(sf::RenderTarget& target);
	void renderEndGameText(sf::RenderTarget& target);
	void endTheGame();
	void render();

	void renderEnd();

};


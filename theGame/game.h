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
	sf::Texture texture;
	sf::Sprite background;
	//game logic 
	bool endGame;
	unsigned int points;
	unsigned int lives;
	unsigned int missileCounter;
	unsigned int maxMissileCounter;
	int backgroundCounter;
	bool keys[4] = { false }; //fix


	std::vector<sf::RectangleShape> missiles;
	sf::RectangleShape missile;

	sf::RectangleShape player;

	void initVariables();
	void initWindow();
	void initFonts();
	void initBackground();
	void initText();
	void initMissile();
	void initPlayer();

	void moveBackground();

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


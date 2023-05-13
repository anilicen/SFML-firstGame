#include "game.h"

void game::initVariables() 
{
	this->window = nullptr;


	this->endGame = false;
	this->points = 0;
	this->lives = 3;
	this->missileCounter = 0;
	this->maxMissileCounter = 5;
	
}

void game::initWindow()
{
	settings.antialiasingLevel = 8.0;
	this->videoMode.height = 900;
	this->videoMode.width = 1600;
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Close | sf::Style::Titlebar,settings);
	
	this->window->setFramerateLimit(144);
}

void game::initFonts()
{
}


void game::initText()
{
}

void game::initMissile()
{

}

void game::initPlayer() 
{
	this->player.setPosition(100.f, 450.f);
	this->player.setSize(sf::Vector2f(100.f, 100.f));
	this->player.setFillColor(sf::Color::Cyan);
}

game::game()
{
	initVariables();
	initWindow();
	initPlayer();

}

game::~game()
{
	delete this->window;
}

const bool game::running() const
{
	return false;
}

const bool game::getEndGame() const
{
	return false;
}

void game::isPlayerHit()
{
}



void game::coinCollect()
{
}

void game::updateCoins()
{
}

void game::updateScore()
{
}

void game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->ev.key.code == sf::Keyboard::Up)
				this->keys[0] = true;
			if (this->ev.key.code == sf::Keyboard::Down)
				this->keys[1] = true;
			if (this->ev.key.code == sf::Keyboard::Left)
				this->keys[2] = true;
			if (this->ev.key.code == sf::Keyboard::Right)
				this->keys[3] = true;
			break;
		}
	}
}


void game::updateMissilePosition()
{
}



void game::moveUp()
{
	if(player.getPosition().y != 0)
	player.move(0.f, -10.f);
}
void game::moveDown()
{
	if (player.getPosition().y != videoMode.height)
		player.move(0.f, 10.f);
}
void game::moveLeft()
{	
	if (player.getPosition().x != 0)
		player.move(-10.f, 0.f);
}
void game::moveRight()
{
	if (player.getPosition().y != videoMode.width)
		player.move(10.f, 0.f);
}

void game::movePlayer()
{
	if (keys[0])
	{
		this->moveUp();
		keys[0] = false;
	}
	if (keys[1])
	{
		this->moveDown();
		keys[1] = false;
	}
	if (keys[2])
	{
		this->moveLeft();
		keys[2] = false;
	}
	if (keys[3])
	{
		this->moveRight();
		keys[3] = false;
	}
}

void game::renderText(sf::RenderTarget& target)
{
}

void game::renderPlayer(sf::RenderTarget& target)
{
	target.draw(this->player);
}

void game::update()
{
	pollEvents();
	movePlayer();
}

void game::render()
{
	this->window->clear();
	this->renderPlayer(*(this->window));
	this->window->display();
}


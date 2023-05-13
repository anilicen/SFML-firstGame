#include "game.h"
#define SPEED 3.0f
#define BACKGROUND_SPEED -1.f
#define MISSILE_HEIGHT 20.f
#define MISSILE_WIDTH 60.f
#define MISSILE_SPEED 5.0f

void game::initVariables() 
{
	this->window = nullptr;


	this->endGame = false;
	this->points = 0;
	this->lives = 3;
	this->missileCounter = 0;
	this->maxMissileCounter = 8;
	this->backgroundCounter = 0;
}

void game::initWindow()
{
	settings.antialiasingLevel = 8;
	this->videoMode.height = 900;
	this->videoMode.width = 1600;
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Close | sf::Style::Titlebar,settings);
	
	this->window->setFramerateLimit(144);
}

void game::initFonts()
{
	font.loadFromFile("fonts/Dosis-Light.ttf");
}

void game::initBackground()
{
	this->texture.loadFromFile("images/background.jpg");
	background.setTexture(texture);
}

void game::initText()
{	
	this->pointsText.setFont(this->font);
	this->pointsText.setString(" ");
	this->pointsText.setCharacterSize(24);
	this->pointsText.setPosition(50.0f, 50.0f);

	this->livesText.setFont(this->font);
	this->livesText.setString(" ");
	this->livesText.setCharacterSize(24);
	this->livesText.setPosition(50.0f, 30.0f);

}

void game::initMissile()
{
	this->missile.setPosition(0.f, 0.f);
	this->missile.setSize(sf::Vector2f(MISSILE_WIDTH, MISSILE_HEIGHT));
	this->missile.setFillColor(sf::Color::Red);
}

void game::initPlayer() 
{
	this->player.setPosition(100.f, 450.f);
	this->player.setSize(sf::Vector2f(80.f, 80.f));
	this->player.setFillColor(sf::Color::Cyan);
}

void game::moveBackground()
{
	background.move(BACKGROUND_SPEED, 0.f);
	backgroundCounter++;
	if (backgroundCounter == 3200)
	{
		backgroundCounter = 0;
		this->initBackground();
	}
}

void game::spawnMissile()
{
	if(missileCounter < maxMissileCounter)
	{
		int y = rand() % int(videoMode.height - 2 * MISSILE_HEIGHT);
		this->missile.setPosition(videoMode.width, y);
		this->missiles.push_back(missile);
		missileCounter++;
	}
}




game::game()
{
	initVariables();
	initWindow();
	initBackground();
	initPlayer();
	initMissile();
	initText();
	initFonts();

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
	for (int i = 0; i < missiles.size(); i++) {
		if (this->player.getGlobalBounds().intersects(missiles[i].getGlobalBounds())) {
			this->lives--;
			this->missiles.erase(this->missiles.begin() + i);
			missileCounter--;
			if (player.getFillColor() == sf::Color::Cyan) {
				player.setFillColor(sf::Color::White);
			}
			else {
				player.setFillColor(sf::Color::Cyan);
			}
		}
	}
}



void game::coinCollect()
{
}

void game::updateCoins()
{
}

void game::updateScore()
{
	this->points++;
}

void game::updateText()
{
	std::stringstream scoreTextStream;
	std::stringstream livesTextStream;
	scoreTextStream << "Points:" << this->points;
	livesTextStream << "Lives: " << this->lives;
	
	pointsText.setString(scoreTextStream.str());
	livesText.setString(livesTextStream.str());

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
			//movement
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
		case sf::Event::KeyReleased:
			if (this->ev.key.code == sf::Keyboard::Up)
				this->keys[0] = false;
			if (this->ev.key.code == sf::Keyboard::Down)
				this->keys[1] = false;
			if (this->ev.key.code == sf::Keyboard::Left)
				this->keys[2] = false;
			if (this->ev.key.code == sf::Keyboard::Right)
				this->keys[3] = false;
		}
	}
}


void game::updateMissilePosition()
{
	for (int i = 0; i < missiles.size(); i++) {
		missiles[i].move(-MISSILE_SPEED, 0.f);
		if (missiles[i].getPosition().x < -MISSILE_WIDTH) {
			this->missiles.erase(this->missiles.begin() + i);
			missileCounter--;
		}
	}
}



void game::moveUp()
{
	if(player.getPosition().y > 0)
	player.move(0.f, -SPEED);
}
void game::moveDown()
{
	if (player.getPosition().y <  videoMode.height-player.getSize().y)
		player.move(0.f, SPEED);
}
void game::moveLeft()
{	
	if (player.getPosition().x > 0)
		player.move(-SPEED, 0.f);
}
void game::moveRight()
{
	if (player.getPosition().x < videoMode.width-player.getSize().x)
		player.move(SPEED, 0.f);
}

void game::movePlayer()
{
	if (keys[0])
	{
		this->moveUp();
	}
	if (keys[1])
	{
		this->moveDown();
	}
	if (keys[2])
	{
		this->moveLeft();
	}
	if (keys[3])
	{
		this->moveRight();
	}
}

void game::renderText(sf::RenderTarget& target)
{
	target.draw(this->livesText);
	target.draw(this->pointsText);
}

void game::renderPlayer(sf::RenderTarget& target)
{
	target.draw(this->player);
}
void game::renderMissile(sf::RenderTarget& target)
{
	for (auto& mis : missiles) {
		target.draw(mis);
	}
}


void game::update()
{

	pollEvents();
	movePlayer();
	spawnMissile();
	updateMissilePosition();
	isPlayerHit();
	updateScore();
	updateText();
		//moveBackground();
}

void game::render()
{	
	this->window->clear();
	this->window->draw(background);
	this->renderPlayer(*(this->window));
	this->renderMissile(*(this->window));
	this->renderText(*(this->window));
	this->window->display();
}


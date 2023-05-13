#include <iostream>
#include "../game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>



int main() {

	game game;



	//Game loop
	while (!game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();
		
		
	}
		
		return 0;
}
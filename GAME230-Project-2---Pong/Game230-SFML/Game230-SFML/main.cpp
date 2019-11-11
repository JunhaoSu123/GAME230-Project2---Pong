#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include<iostream>
#include"Game_State.h"
#include"Main_Menu.h"

game_state coreState;
bool quitGame = false;
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong!");

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		coreState.Update();
		coreState.Render();

		//window.clear();
		//window.draw(shape);
		window.display();
		if (quitGame) {
			window.close();
		}
		Sleep(5);
	}

	return 0;
}

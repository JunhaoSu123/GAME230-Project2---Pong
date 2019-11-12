#pragma once
#include "Game_State.h"

class win_state : public tiny_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);


private:
	sf::Font* font;
	sf::Text* gameOver;
	sf::Text* win1;
	sf::Text* win2;
	sf::Text* esc;
	sf::Text* playAgain;
	bool Player1Win, Player2Win;
};
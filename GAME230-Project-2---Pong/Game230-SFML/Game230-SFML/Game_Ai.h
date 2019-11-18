#pragma once

#include "game_state.h"
#include "player.h"
#include "Ai.h"
#include "ball_ai.h"
#include "score.h"

class game_ai : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	player* player1;
	ai* player2;
	ball_ai* ballObject;
	score* score1;
	score* score2;
	sf::Text* pausedText;

	sf::Font* font;

};
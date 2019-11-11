#pragma once
#include "Game_State.h"
#include"Player_Ai.h"
#include"Player.h"
#include"Ball_Ai.h"
#include"Score.h"

class game_play_ai : public tiny_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);


private:
	player* player1;
	player_ai* player2;
	ball_ai* ballObject;
	score* score1;
	score* score2;

	sf::Font* font;

};
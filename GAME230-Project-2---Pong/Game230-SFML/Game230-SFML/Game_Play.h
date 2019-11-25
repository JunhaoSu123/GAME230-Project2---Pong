#pragma once
#include "Game_State.h"
#include"Player.h"
#include"Ball.h"
#include"Score.h"
#include"Obstacle.h"
#include"Hole.h"
#include"PowerUp.h"

class game_play : public tiny_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);


private:
	player* player1;
	player* player2;
	ball* ballObject;
	score* score3;
	score* socre4;
	obstacle* ob;
	hole* ho;
	powerup* pu;
	sf::Font* font;

};
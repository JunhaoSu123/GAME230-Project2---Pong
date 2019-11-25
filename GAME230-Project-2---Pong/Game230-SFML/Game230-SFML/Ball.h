#pragma once
#include "player.h"
#include"Score.h"
#include"Obstacle.h"
#include"Hole.h"
#include"PowerUp.h"
#include<SFML/Audio.hpp>

class ball : public GameObject {
public:
	ball(score* score3, score* socre4, player* player1, player* player2, obstacle* ob, hole* ho, powerup* pu);
	void Update(sf::RenderWindow* window);
	~ball();
private:
	score* score3;
	score* socre4;
	player* player1;
	player* player2;
	obstacle* ob;
	hole* ho;
	powerup* pu;

	sf::SoundBuffer* bufferBounce;
	sf::SoundBuffer* bufferGoal;
	sf::Sound* soundBounce;
	sf::Sound* soundGoal;
};
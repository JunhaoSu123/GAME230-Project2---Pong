#pragma once
#include "player.h"
#include"Score.h"
#include"Obstacle.h"
#include<SFML/Audio.hpp>

class ball : public GameObject {
public:
	ball(score* score3, score* socre4, player* player1, player* player2, obstacle* ob);
	void Update(sf::RenderWindow* window);
	~ball();
private:
	score* score3;
	score* socre4;
	player* player1;
	player* player2;
	obstacle* ob;

	sf::SoundBuffer* bufferBounce;
	sf::SoundBuffer* bufferGoal;
	sf::Sound* soundBounce;
	sf::Sound* soundGoal;
};
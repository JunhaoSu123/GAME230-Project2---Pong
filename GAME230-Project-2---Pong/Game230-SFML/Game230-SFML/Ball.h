#pragma once
#include "player.h"
#include"Score.h"
#include<SFML/Audio.hpp>

class ball : public GameObject {
public:
	ball(score* socre1, score* socre2, player* player1, player* player2);
	void Update(sf::RenderWindow* window);
	~ball();
private:
	score* score1;
	score* score2;
	player* player1;
	player* player2;

	sf::SoundBuffer* bufferBounce;
	sf::SoundBuffer* bufferGoal;
	sf::Sound* soundBounce;
	sf::Sound* soundGoal;
};
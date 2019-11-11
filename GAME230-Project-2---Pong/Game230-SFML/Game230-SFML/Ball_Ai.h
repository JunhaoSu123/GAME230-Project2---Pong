#pragma once
#include "Player_ai.h"
#include"Score.h"
#include<SFML/Audio.hpp>

class ball_ai : public GameObject {
public:
	ball_ai(score* socre1, score* socre2, paddle* player1, paddle* player2);
	void Update(sf::RenderWindow* window);
	~ball_ai();
private:
	score* score1;
	score* score2;
	paddle* player1;
	paddle* player2;

	sf::SoundBuffer* bufferBounce;
	sf::SoundBuffer* bufferGoal;
	sf::Sound* soundBounce;
	sf::Sound* soundGoal;
};
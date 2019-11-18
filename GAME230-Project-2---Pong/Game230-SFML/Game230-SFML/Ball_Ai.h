#pragma once

#include <SFML/Audio.hpp>
#include "player.h"
#include "score.h"

class ball_ai : public GameObject
{
public:
	ball_ai(score* score1, score* score2, paddle* player1, paddle* player2);
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
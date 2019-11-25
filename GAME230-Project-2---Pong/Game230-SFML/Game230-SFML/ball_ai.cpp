#include "Ball_Ai.h"
#include"Score.h"
#include"Game_State.h"
#include"Main_Menu.h"
#include "WinState.h"
float ballaiCenter;
ball_ai::ball_ai(score* score1, score* score2, paddle* player1, paddle* player2) {
	this->Load("Ball.png");

	this->score1 = score1;
	this->score2 = score2;

	this->player1 = player1;
	this->player2 = player2;

	this->velocity.x = 1.75f;
	this->velocity.y = -0.45f;

	this->bufferBounce = new sf::SoundBuffer();
	this->bufferBounce->loadFromFile("Sounds/WaterDrop.wav");
	this->soundBounce = new sf::Sound(*this->bufferBounce);

	this->bufferGoal = new sf::SoundBuffer();
	this->bufferGoal->loadFromFile("Sounds/Goal.wav");
	this->soundGoal = new sf::Sound(*this->bufferGoal);

}
void ball_ai::Update(sf::RenderWindow* window) {
	if (this->velocity.x < 0 && this->CollisionCheck(this->player1)) {

		if (ballaiCenter < this->player1->getPosition().y + this->player1->getGlobalBounds().height / 3) {
			if (this->velocity.y > 0) {
				this->velocity.y *= -1.03f;
			}
			if (this->velocity.y < 0) {
				this->velocity.y *= 1.03f;
			}
		}
		if (ballaiCenter > this->player1->getPosition().y + this->player1->getGlobalBounds().height / 2) {
			if (this->velocity.y < 0) {
				this->velocity.y *= -1.03f;
			}
			if (this->velocity.y > 0) {
				this->velocity.y *= 1.03f;
			}
		}

		this->velocity.x *= -1.03f;
		this->soundBounce->play();
	}
	if (this->velocity.x > 0 && this->CollisionCheck(this->player2)) {
		if (ballaiCenter < this->player2->getPosition().y + this->player2->getGlobalBounds().height / 3) {
			if (this->velocity.y > 0) {
				this->velocity.y *= -1.03f;
			}
			if (this->velocity.y < 0) {
				this->velocity.y *= 1.03f;
			}
		}
		if (ballaiCenter > this->player2->getPosition().y + this->player2->getGlobalBounds().height / 2) {
			if (this->velocity.y < 0) {
				this->velocity.y *= -1.03f;
			}
			if (this->velocity.y > 0) {
				this->velocity.y *= 1.03f;
			}
		}
		this->velocity.x *= -1.03f;
		this->soundBounce->play();
	}

	if (this->getPosition().y < 0 || this->getPosition().y > 565) {
		this->velocity.y *= -1.0f;
		this->soundBounce->play();
	}

	if (this->getPosition().x < -10) {
		this->score2->PlusOne();
		whoWon = true;
		this->soundGoal->play();
		this->setPosition(window->getSize().x / 2 - 15, window->getSize().y / 2 - 30);
		this->velocity.x = -1.75f;
	}

	if (this->getPosition().x > 790) {
		this->score1->PlusOne();
		whoWon = false;
		this->soundGoal->play();
		this->setPosition(window->getSize().x / 2 - 15, window->getSize().y / 2 - 30);
		this->velocity.x = 1.75f;
	}
	GameObject::Update();
	ballaiCenter = this->getPosition().y + this->getGlobalBounds().height / 2;
}
ball_ai::~ball_ai() {
	delete this->bufferBounce;
	delete this->bufferGoal;
	delete this->soundBounce;
	delete this->soundGoal;
}
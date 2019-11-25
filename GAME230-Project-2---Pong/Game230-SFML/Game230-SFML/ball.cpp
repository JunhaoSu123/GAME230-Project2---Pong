#include "Ball.h"
#include"Score.h"
#include"Game_State.h"
#include"Main_Menu.h"
#include "WinState.h"
#include"Player.h"
#include"Hole.h"
#include"PowerUp.h"

float paddleCenter1;
float paddleCenter2;
float ballCenter;
//float bounce;
//float angle;
bool getOb = false;
bool getho = false;
bool whoWon;
ball::ball(score* score3, score* socre4, player* player1, player* player2, obstacle* ob, hole* ho, powerup* pu) {
	this->Load("Ball.png");

	this->score3 = score3;
	this->socre4 = socre4;

	this->player1 = player1;
	this->player2 = player2;
	this->ob = ob;
	this->ho = ho;
	this->pu = pu;

	this->velocity.x = 1.0f;
	this->velocity.y = -0.4f;

	this->bufferBounce = new sf::SoundBuffer();
	this->bufferBounce->loadFromFile("Sounds/WaterDrop.wav");
	this->soundBounce = new sf::Sound(*this->bufferBounce);

	this->bufferGoal = new sf::SoundBuffer();
	this->bufferGoal->loadFromFile("Sounds/Goal.wav");
	this->soundGoal = new sf::Sound(*this->bufferGoal);

}

void ball::Update(sf::RenderWindow* window) {
	//bounce = (paddleCenter - ballCenter)/paddleCenter;
	//angle = bounce * 1.309f;
	if (this->velocity.x < 0 && this->CollisionCheck(this->player1)) {
		//this->velocity.x *= cos(angle);
		//this->velocity.y *= -sin(angle);

		if (ballCenter < this->player1->getPosition().y+this->player1->getGlobalBounds().height/3) {
			if (this->velocity.y > 0) {
				this->velocity.y *= -1.03f;
			}
			if (this->velocity.y < 0) {
				this->velocity.y *= 1.03f;
			}
		}
		if (ballCenter > this->player1->getPosition().y + this->player1->getGlobalBounds().height / 2) {
			if (this->velocity.y < 0) {
				this->velocity.y *= -1.03f;
			}
			if (this->velocity.y > 0) {
				this->velocity.y *= 1.03f;
			}
		}

		this->velocity.x *= -1.03f;
		this->soundBounce->play();
		getOb = true;
		getho = true;
	}
	if (this->velocity.x > 0 && this->CollisionCheck(this->player2)) {
		//this->velocity.x *= cos(angle);
		//this->velocity.y *= -sin(angle);
		if (ballCenter < this->player2->getPosition().y + this->player2->getGlobalBounds().height / 3) {
			if (this->velocity.y > 0) {
				this->velocity.y *= -1.03f;
			}
			if (this->velocity.y < 0) {
				this->velocity.y *= 1.03f;
			}
		}
		if (ballCenter > this->player2->getPosition().y + this->player2->getGlobalBounds().height / 2) {
			if (this->velocity.y < 0) {
				this->velocity.y *= -1.03f;
			}
			if (this->velocity.y > 0) {
				this->velocity.y *= 1.03f;
			}
		}
		this->velocity.x *= -1.03f;
		this->soundBounce->play();
		getOb = true;
		getho = true;
	}

	if (powerUp == true && this->CollisionCheck(this->pu)) {
		if (this->velocity.x > 0) {
			p1power = true;
		}
		if (this->velocity.x < 0) {
			p2power = true;
		}
		powerUp = false;
	}

	if (obActive == true && getOb == true && this->CollisionCheck(this->ob)) {
		this->velocity.x *= -1.0f;
		this->soundBounce->play();
		getOb = false;
	}

	if (hoActive == true && getho == true && this->CollisionCheck(this->ho)) {
		if (this->velocity.x < 0 && this->velocity.y < 0) {
			this->velocity.y -= 0.7f;
			getho = false;
		}
		if (this->velocity.x < 0 && this->velocity.y > 0) {
			this->velocity.y += 0.7f;
			getho = false;
		}
		if (this->velocity.x > 0 && this->velocity.y < 0) {
			this->velocity.y -= 0.7f;
			getho = false;
		}
		if (this->velocity.x > 0 && this->velocity.y > 0) {
			this->velocity.y += 0.7f;
			getho = false;
		}
	}
	if (this->getPosition().y < 0 || this->getPosition().y > 565){
		this->velocity.y *= -1.0f;
		this->soundBounce->play();
	}

	if (this->getPosition().x < -10) {
		this->socre4->PlusOne();
		whoWon = true;
		getho = false;
		this->soundGoal->play();
		this->setPosition(window->getSize().x / 2-50, window->getSize().y / 2 - 30);
		this->velocity.x = -1.0f;
		this->velocity.y = -0.4f;
	}

	if (this->getPosition().x >790) {
		this->score3->PlusOne();
		whoWon = false;
		getho = false;
		this->soundGoal->play();
		this->setPosition(window->getSize().x / 2+2, window->getSize().y / 2 - 30);
		this->velocity.x = 1.0f;
		this->velocity.y = 0.4f;
	}
	GameObject::Update();
	ballCenter = this->getPosition().y + this->getGlobalBounds().height / 2;
}
ball::~ball() {
	delete this->bufferBounce;
	delete this->bufferGoal;
	delete this->soundBounce;
	delete this->soundGoal;
}
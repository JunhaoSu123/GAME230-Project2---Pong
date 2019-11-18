#include <iostream>
#include"Main_Menu.h"
#include"Game_Play.h"
#include"Score.h"
#include"WinState.h"
#include"Game_State.h"
#include"Game_Ai.h"

void game_ai::Initialize(sf::RenderWindow* window)
{
	this->font = new sf::Font();
	this->font->loadFromFile("font.otf");
	this->score1 = new score(*font, 32U);
	this->score2 = new score(*font, 32U);

	this->score2->setPosition(window->getSize().x - this->score1->getGlobalBounds().width, 0);

	this->player1 = new player(0);
	this->player2 = new ai(1);

	this->player1->setPosition(0, 240);
	this->player2->setPosition(783, 240);

	this->ballObject = new ball_ai(this->score1, this->score2, this->player1, this->player2);
	this->ballObject->setPosition(window->getSize().x / 2 - 15, window->getSize().y / 2 - 30);
	this->player2->SetBall(this->ballObject);

}
void game_ai::Update(sf::RenderWindow* window) {
	this->ballObject->Update(window);
	this->player1->Update();
	this->player2->Update();
	this->score1->Update();
	this->score2->Update();
	this->score1->WinCheck();
	this->score2->WinCheck();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new main_menu());
	}
	if (win) {

		coreState.SetState(new win_state());
	}
}
void game_ai::Render(sf::RenderWindow* window)
{
	this->player1->setScale(0.25f, 0.5f);
	this->player2->setScale(0.25f, 0.5f);
	this->ballObject->setScale(0.5f, 0.5f);

	window->draw(*this->ballObject);
	window->draw(*this->player1);
	window->draw(*this->player2);
	window->draw(*this->score1);
	window->draw(*this->score2);
}
void game_ai::Destroy(sf::RenderWindow* window)
{
	delete this->player1;
	delete this->player2;
	delete this->ballObject;
	delete this->score1;
	delete this->score2;

	delete this->font;
}
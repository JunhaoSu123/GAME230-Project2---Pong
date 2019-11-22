#include <iostream>
#include"Main_Menu.h"
#include"Game_Play.h"
#include"Score.h"
#include"WinState.h"
#include"Game_State.h"
#include"Obstacle.h"
#include"Hole.h"

bool win = false;
bool activeAI = false;
void game_play::Initialize(sf::RenderWindow* window) {
	this->font = new sf::Font();
	this->font->loadFromFile("font.otf");
	this->score3 = new score(*font, 32U);
	this->socre4 = new score(*font, 32U);
	
	this->ob = new obstacle;
	this->ob->setPosition(window->getSize().x / 2 - 15, window->getSize().y/2 + 50);

	this->ho = new hole;
	this->ho->setPosition(window->getSize().x / 2 - 85 , window->getSize().y / 2-120);

	this->socre4->setPosition(window->getSize().x - this->score3->getGlobalBounds().width, 0);
	
	this->player1 = new player(0);
	this->player2 = new player(1);

	this->player1->setPosition(0, 240);
	this->player2->setPosition(783, 240); 

	this->ballObject = new ball(this->score3, this->socre4, this->player1, this->player2, this->ob, this->ho);
	this->ballObject->setPosition(window->getSize().x / 2-15, window->getSize().y / 2-30);
}
void game_play::Update(sf::RenderWindow* window) {
	this->ballObject->Update(window);
	this->player1->Update();
	this->player2->Update();
	this->ob->Update(window);
	this->score3->Update();
	this->socre4->Update();
	this->score3->WinCheck();
	this->socre4->WinCheck();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new main_menu());
	}
	if (win) {

		coreState.SetState(new win_state());
	}
}
void game_play::Render(sf::RenderWindow* window) {
	this->player1->setScale(0.25f, 0.5f);
	this->player2->setScale(0.25f, 0.5f);
	this->ballObject->setScale(0.5f, 0.5f);
	this->ob->setScale(0.25f, 0.5f);
	this->ho->setScale(0.7f, 0.7f);
	if (obActive) {
		window->draw(*this->ob);
	}

	if (hoActive) {
		window->draw(*this->ho);
	}
	window->draw(*this->ballObject);
	window->draw(*this->player1);
	window->draw(*this->player2);
	window->draw(*this->score3);
	window->draw(*this->socre4);
}
void game_play::Destroy(sf::RenderWindow* window) {
	delete this->player1;
	delete this->player2;
	delete this->ballObject;
	delete this->score3;
	delete this->socre4;
	delete this->font;
	delete this->ob;
}

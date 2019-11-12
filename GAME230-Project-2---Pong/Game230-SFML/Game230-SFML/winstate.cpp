#include <iostream>
#include"WinState.h"
#include"Game_Play.h"
#include"Ball.h"
#include"Main_Menu.h"
#include"Score.h"
#include"GameObject.h"


void win_state::Initialize(sf::RenderWindow* window) {
	this->Player1Win = false;
	this->Player2Win = false;

	this->font = new sf::Font();
	this->font->loadFromFile("font.otf");

	this->gameOver = new sf::Text("Game Over", *this->font, 100U);
	this->gameOver->setOrigin(this->gameOver->getGlobalBounds().width / 2, this->gameOver->getGlobalBounds().height / 2);
	this->gameOver->setPosition(window->getSize().x / 2, window->getSize().y / 5);

	this->win1 = new sf::Text("Yellow Player Won!", *this->font, 32U);
	this->win1->setOrigin(this->win1->getGlobalBounds().width / 2, this->win1->getGlobalBounds().height / 2);
	this->win1->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 20);

	this->win2 = new sf::Text("Blue Player Won!", *this->font, 32U);
	this->win2->setOrigin(this->win2->getGlobalBounds().width / 2, this->win2->getGlobalBounds().height / 2);
	this->win2->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 20);

	this->esc = new sf::Text("Press ESC to back to main menu", *this->font, 32U);
	this->esc->setOrigin(this->esc->getGlobalBounds().width / 2, this->esc->getGlobalBounds().height / 2);
	this->esc->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 140);

	this->playAgain = new sf::Text("Press SPACE to play again", *this->font, 32U);
	this->playAgain->setOrigin(this->playAgain->getGlobalBounds().width / 2, this->playAgain->getGlobalBounds().height / 2);
	this->playAgain->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 100);


}
void win_state::Update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new main_menu());
		win = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		coreState.SetState(new game_play());
		win = false;
	}


}
void win_state::Render(sf::RenderWindow* window) {

	this->gameOver->setFillColor(sf::Color::White);
	this->win1->setFillColor(sf::Color::Yellow);
	this->win2->setFillColor(sf::Color::Blue);
	this->esc->setFillColor(sf::Color::White);
	this->playAgain->setFillColor(sf::Color::White);
	if (whoWon == true) {
		window->draw(*this->win2);
	}
	if (whoWon == false) {
		window->draw(*this->win1);
	}
	window->draw(*this->gameOver);
	window->draw(*this->esc);
	window->draw(*this->playAgain);

}

void win_state::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->gameOver;
	delete this->win1;
	delete this->win2;
	delete this->esc;
	delete this->playAgain;
}

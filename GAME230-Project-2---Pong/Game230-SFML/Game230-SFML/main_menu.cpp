#include <iostream>
#include"Main_Menu.h"
#include"Game_Play.h"

void main_menu::Initialize(sf::RenderWindow* window) {
	
	this->ButtonSelect = 0;

	this->font = new sf::Font();
	this->font->loadFromFile("font.otf");

	this->title = new sf::Text("Pong", *this->font, 128U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 5);

	this->PVE = new sf::Text("Player VS AI", *this->font, 32U);
	this->PVE->setOrigin(this->PVE->getGlobalBounds().width / 2, this->PVE->getGlobalBounds().height / 2);
	this->PVE->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 20);

	this->PVP = new sf::Text("Player VS Player", *this->font, 32U);
	this->PVP->setOrigin(this->PVP->getGlobalBounds().width / 2, this->PVP->getGlobalBounds().height / 2);
	this->PVP->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 60);

	this->Mod1 = new sf::Text("Mod1", *this->font, 32U);
	this->Mod1->setOrigin(this->Mod1->getGlobalBounds().width / 2, this->Mod1->getGlobalBounds().height / 2);
	this->Mod1->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 100);

	this->Mod2 = new sf::Text("Mod2", *this->font, 32U);
	this->Mod2->setOrigin(this->Mod2->getGlobalBounds().width / 2, this->Mod2->getGlobalBounds().height / 2);
	this->Mod2->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 140);

	this->quit = new sf::Text("Quit", *this->font, 32U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 180);

	
}
void main_menu::Update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->Upkey) {
		this->ButtonSelect -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down	) && !this->Downkey) {
		this->ButtonSelect += 1;
	}
	if (this->ButtonSelect > 4) {
		this->ButtonSelect = 0;
	}
	if (this->ButtonSelect < 0) {
		this->ButtonSelect = 4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		switch (this->ButtonSelect) {
		case 0:
			Ai = true;
			break;
		case 1:
			coreState.SetState(new game_play());
			break;
		case 2:
			//coreState.SetState(new game_play_ai());
			break;
		case 3:
			//coreState.SetState(new game_play());
			break;
		case 4:
			quitGame = true;
			break;
		}
	}
	this->Upkey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->Downkey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

}
void main_menu::Render(sf::RenderWindow* window) {

	this->PVE->setFillColor(sf::Color::White);
	this->PVP->setFillColor(sf::Color::White);
	this->Mod1->setFillColor(sf::Color::White);
	this->Mod2->setFillColor(sf::Color::White);
	this->quit->setFillColor(sf::Color::White);


	switch(this->ButtonSelect){
	case 0:
		this->PVE->setFillColor(sf::Color::Red);
		break;
	case 1:
		this->PVP->setFillColor(sf::Color::Red);
		break;
	case 2:
		this->Mod1->setFillColor(sf::Color::Red);
		break;
	case 3:
		this->Mod2->setFillColor(sf::Color::Red);
		break;
	case 4:
		this->quit->setFillColor(sf::Color::Red);
		break;
	}

	window->draw(*this->title);
	window->draw(*this->PVE);
	window->draw(*this->PVP);
	window->draw(*this->Mod1);
	window->draw(*this->Mod2);
	window->draw(*this->quit);
}
void main_menu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title;
	delete this->PVE;
	delete this->PVP;
	delete this->Mod1;
	delete this->Mod2;
	delete this->quit;
}

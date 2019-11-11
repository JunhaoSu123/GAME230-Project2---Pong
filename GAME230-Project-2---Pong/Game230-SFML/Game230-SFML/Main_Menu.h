#pragma once
#include "Game_State.h"

class main_menu : public tiny_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);


private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* PVE;
	sf::Text* PVP;
	sf::Text* Mod1;
	sf::Text* Mod2;
	sf::Text* quit;

	int ButtonSelect;
	bool Upkey, Downkey;
};
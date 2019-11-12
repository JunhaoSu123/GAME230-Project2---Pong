#include "Score.h"
#include "GameObject.h"

score::score(sf::Font &font, unsigned int size):sf::Text("Score: 0", font, size) {
	this->points = 0;
}
void score::PlusOne() {
	this->points += 1;
}
void score::Update() {
	this->setString("Score: " + std::to_string(this->points));
}
void score::WinCheck() {
	if (this->points == 5) {
		win = true;
	}

}
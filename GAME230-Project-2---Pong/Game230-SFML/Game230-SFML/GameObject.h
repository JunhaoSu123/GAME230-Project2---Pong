#pragma once
#include<SFML/Graphics.hpp>
#include<string>

class GameObject : public sf::Sprite {
public:
	GameObject() {
		this->texture = new sf::Texture();
	}

	void Load(std::string filename) {
		this->texture->loadFromFile("Sprites/" + filename);
		this->setTexture(*this->texture);
	}

	virtual void Update() {
		this->move(this->velocity);
	}
	bool CollisionCheck(GameObject* gameobject) {
		return this->getGlobalBounds().intersects(gameobject->getGlobalBounds());
	}
	~GameObject() {
		delete this->texture;
	}

protected:
	sf::Vector2f velocity;

private:
	sf::Texture* texture;

};
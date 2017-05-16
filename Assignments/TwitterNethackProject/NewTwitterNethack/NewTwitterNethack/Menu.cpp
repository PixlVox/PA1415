#include "Menu.h"
#include <iostream>

Menu::Menu(){

	this->startTexture.loadFromFile("Textures//Menu//NewGameButton.png");
	this->menuSprite[0].setTexture(this->startTexture);
	this->menuSprite[0].setPosition(sf::Vector2f(900, 400));

	this->exitTexture.loadFromFile("Textures//Menu//ExitButton.png");
	this->menuSprite[1].setTexture(this->exitTexture);
	this->menuSprite[1].setPosition(sf::Vector2f(900, 500));

	this->highlightTexture.loadFromFile("Textures//Menu//ButtonHighlight.png");
	this->menuSprite[2].setTexture(this->highlightTexture);
	this->menuSprite[2].setPosition(sf::Vector2f(891, 395));
	this->menuSprite[2].setScale(sf::Vector2f(1.2, 1.0));

	this->transparency.setSize(sf::Vector2f(1920.0f, 1080.0f));
	this->transparency.setFillColor(sf::Color(50, 50, 50, 220));

	this->current = 0;
	this->menuTimer = 0.1f;

}

int Menu::detectKey(float deltaTime){

	this->menuTimer += deltaTime;
	int option = 1;

	if (menuTimer >= 0.1f) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			if (current >= 1) {

				current = 0;
				this->menuSprite[2].setPosition(891, 395);

			}
			else {

				this->current++;
				this->menuSprite[2].setPosition(891, 495);

			}

		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

			if (current <= 0) {

				current = 1;
				this->menuSprite[2].setPosition(891, 495);

			}
			else {

				this->current--;
				this->menuSprite[2].setPosition(891, 395);

			}

		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

			if (this->current == 0) {

				option = 2;

			}
			else if(this->current == 1){

				option = 0;

			}

		}

		this->menuTimer = 0.0f;

	}

	std::cout << "Current: " << option << std::endl;

	return option;

}

void Menu::drawButtons(sf::RenderWindow& window) {

	window.draw(this->transparency);

	for (int i = 2; i >= 0; i--) {

		window.draw(this->menuSprite[i]);

	}

}
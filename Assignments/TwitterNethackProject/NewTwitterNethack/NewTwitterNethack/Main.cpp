#include"GameHandler.h"
#include <iostream>


int main() {

	//Setup window
	sf::RenderWindow window(sf::VideoMode(1920, 1080) , "TwitterNethack", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	GameHandler game;

	//Deltatime
	sf::Clock deltaClock;
	float deltaTime = 0.0f;

	while (window.isOpen()) {

		//Update deltaTime
		deltaTime = deltaClock.restart().asSeconds();

		//Handle events
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

		}

		game.update(deltaTime);
		game.updateSprites(deltaTime);

		//Window update screen
		window.clear();

		window.draw(game);
		game.drawObjects(window);

		window.display();

	}

	return 0;

}
#include <iostream>
#include "Room.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(1920, 1080) , "TwitterNethack", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	Room room;

	room.generateTiles();
	room.loadVertexArray();

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

		}

		window.clear();

		window.draw(room);

		window.display();

	}

	return 0;

}
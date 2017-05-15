#include "Room.h"
#include <iostream>

void updateCurrentTile(sf::Vector2f playerPos, sf::Vector2i& currentTile);

int main() {

	sf::RenderWindow window(sf::VideoMode(1920, 1080) , "TwitterNethack", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	Room* room = nullptr;
	int** tileMap;
	sf::Vector2i nrOfTiles(30, 17);
	sf::Vector2i currentTile(15, 7);


	while (window.isOpen()) {

		std::cout << "X: " << currentTile.x << "Y: " << currentTile.y << std::endl;

		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

				if (room != nullptr) {

					delete room;

				}

				room = new Room();
				room->createRoom();
				tileMap = room->getTileMap();				
			}

		}

	
		window.clear();

		if (room != nullptr) {

			window.draw(*room);

		}

		window.display();

	}

	return 0;

}

void updateCurrentTile(sf::Vector2f playerPos, sf::Vector2i& currentTile) {

	if (playerPos.x < (currentTile.x * 64)) {

		currentTile.x -= 1;

	}
	else if (playerPos.x > ((currentTile.x + 1) * 64)) {

		currentTile.x += 1;

	}

	if (playerPos.y < (currentTile.y * 64)) {

		currentTile.y -= 1;

	}
	else if (playerPos.y > ((currentTile.y + 1) * 64)) {

		currentTile.y += 1;

	}

}
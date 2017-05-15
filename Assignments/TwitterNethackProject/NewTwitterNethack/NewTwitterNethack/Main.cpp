#include "Room.h"
#include "Player.h"
#include "Portal.h"
#include <iostream>

void updateCurrentTile(sf::Vector2f playerPos, sf::Vector2i& currentTile);

int main() {

	//Setup window
	sf::RenderWindow window(sf::VideoMode(1920, 1080) , "TwitterNethack", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	//Temp
	Room* room = nullptr;
	Player player(sf::Vector2f((64 * 15), (64 * 7)));
	int** tileMap;
	sf::Vector2i nrOfTiles(30, 17);
	sf::Vector2i currentTile(15, 7);

	bool collisionPortal = false;

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

			//Temp
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || collisionPortal) {

				if (room != nullptr) {

					delete room;

				}

				room = new Room();

				player.getBody().setPosition(room->getRandomWalkableTile());
				collisionPortal = false;

			}

		}

		//Temp
		if (room != nullptr) {

			if (player.getBody().getGlobalBounds().intersects(room->getPortal().getGlobalBounds())) {

				collisionPortal = true;

			}

		}

		player.update(deltaTime);

		//Window update screen
		window.clear();

		//Temp
		if (room != nullptr) {

			window.draw(*room);
			room->drawObjects(window);
			room->updateSprites(deltaTime);

		}

		window.draw(player.getBody());

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
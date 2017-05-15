#include "Room.h"
#include "Portal.h"
#include <iostream>

void updateCurrentTile(sf::Vector2f playerPos, sf::Vector2i& currentTile);

int main() {

	sf::RenderWindow window(sf::VideoMode(1920, 1080) , "TwitterNethack", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	Room* room = nullptr;
	int** tileMap;
	sf::Vector2i nrOfTiles(30, 17);
	sf::Vector2i currentTile(15, 7);

<<<<<<< HEAD
	sf::RectangleShape player;
	player.setPosition((15 * 64), (7 * 64));
	player.setSize(sf::Vector2f(50.0f, 50.0f));
	player.setFillColor(sf::Color::Red);
=======
>>>>>>> f7c161473222f2c9cde687d09bd4f65238a30d7d

	bool collisionPortal = false;

	sf::Clock deltaClock;
	float deltaTime = 0.0f;

	while (window.isOpen()) {

		deltaTime = deltaClock.restart().asSeconds();

		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || collisionPortal) {

				if (room != nullptr) {

					delete room;

				}

				room = new Room();
				room->createRoom();
<<<<<<< HEAD
				tileMap = room->getTileMap();

				collisionPortal = false;

=======
				tileMap = room->getTileMap();				
>>>>>>> f7c161473222f2c9cde687d09bd4f65238a30d7d
			}

		}

<<<<<<< HEAD
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

			player.move(0.0f, -5.0f);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			
			player.move(0.0f, 5.0f);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

			player.move(-5.0f, 0.0f);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			player.move(5.0f, 0.0f);

		}

		if (room != nullptr) {

			if (player.getGlobalBounds().intersects(room->getPortal().getGlobalBounds())) {

				collisionPortal = true;

			}

		}

		updateCurrentTile(player.getPosition(), currentTile);

=======
	
>>>>>>> f7c161473222f2c9cde687d09bd4f65238a30d7d
		window.clear();

		if (room != nullptr) {

			window.draw(*room);
			window.draw(room->getPortal());
			room->updateSprites(deltaTime);

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
#include "Room.h"
#include "Player.h"
#include "Portal.h"
#include"Item.h"
#include <iostream>
<<<<<<< HEAD
#include "Room.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(1920, 1080) , "TwitterNethack", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	Room room;

	room.generateTiles();
	room.loadVertexArray();

	while (window.isOpen()) {

		sf::Event event;

=======

void updateCurrentTile(sf::Vector2f playerPos, sf::Vector2i& currentTile);
void updatePlayerBounds(int** tileMap, sf::Vector2i& currentTile, Player& player, sf::RectangleShape* rects);

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

	sf::RectangleShape* rects = new sf::RectangleShape[4];
	
	for (int i = 0; i < 4; i++) {

		rects[i].setPosition(0, 0);
		rects[i].setSize(sf::Vector2f(64.0f, 64.0f));
		rects[i].setFillColor(sf::Color::Red);

	}

	bool collisionPortal = false;

	//Deltatime
	sf::Clock deltaClock;
	float deltaTime = 0.0f;

	while (window.isOpen()) {

		//Update deltaTime
		deltaTime = deltaClock.restart().asSeconds();

		//Handle events
		sf::Event event;
>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

<<<<<<< HEAD
		}

		window.clear();

		window.draw(room);
=======
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					collisionPortal = true;
				}
			}


			//Temp
			if (collisionPortal) {

				if (room != nullptr) {

					delete room;

				}

				room = new Room();
				tileMap = room->getTileMap();

				for (int i = 0; i < 17; i++) {

					std::cout << "\n";

					for (int j = 0; j < 30; j++) {

						std::cout << tileMap[i][j] << " ";

					}


				}

				player.getBody().setPosition(room->getRandomWalkableTile());
				collisionPortal = false;

			}

		}

		//Temp
		if (room != nullptr) {

			updatePlayerBounds(tileMap, currentTile, player, rects);

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

		for (int i = 0; i < 4; i++) {

			window.draw(rects[i]);

		}

		window.draw(player.getBody());
>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109

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

void updatePlayerBounds(int** tileMap, sf::Vector2i& currentTile, Player& player, sf::RectangleShape* rects) {

	//Update player indexed positon
	currentTile.x = ((player.getBody().getPosition().x + player.getBody().getGlobalBounds().width) / 64);
	currentTile.y = ((player.getBody().getPosition().y + player.getBody().getGlobalBounds().height) / 64);

	int left = (currentTile.x -
		tileMap[currentTile.y][(currentTile.x - 1)]) * 64;

	int right = (currentTile.x +
		tileMap[currentTile.y][(currentTile.x)]) * 64;

	int top = (currentTile.y -
		tileMap[(currentTile.y - 1)][(currentTile.x)]) * 64;
	
	int bottom = (currentTile.y +
			tileMap[(currentTile.y)][currentTile.x]) * 64;

	player.updateMovementBounds(left, right, top, bottom);
	
	rects[0].setPosition(left, currentTile.y * 64);
	rects[1].setPosition(right, currentTile.y * 64);
	rects[2].setPosition(currentTile.x * 64, top);
	rects[3].setPosition(currentTile.x * 64, bottom);

}
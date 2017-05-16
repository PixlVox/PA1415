#include "GameHandler.h"

GameHandler::GameHandler(){

	//Initialize values
	this->room = nullptr;
	this->player = nullptr;
	this->tileMap = nullptr;
	this->showMenu = true;
	this->menuTimer = 0.0f;

	//Generate Room 
	this->generateRoom();

	//Set startposition for player
	this->player = new Player(this->room->getRandomWalkableTile());

}

void GameHandler::reset(){

	//Recreate Room
	this->generateRoom();

	//Recreate Player
	delete this->player;
	this->player = new Player(this->room->getRandomWalkableTile());

}

bool GameHandler::updatePortalCollision(){

	bool collision = false;

	if (this->player->getBody().getGlobalBounds().intersects(this->room->getPortal().getGlobalBounds())){

		this->generateRoom();
		collision = true;

	}

	return collision;

}

void GameHandler::draw(sf::RenderTarget &target, sf::RenderStates states) const{

	target.draw(*this->room, states);

}

void GameHandler::drawObjects(sf::RenderWindow& window) {

	this->room->drawObjects(window);

	this->player->drawPlayerAndInventory(window);

	if (this->showMenu) {

		this->menu.drawButtons(window);

	}

}

void GameHandler::itemCollision(void) {

	for (int i = 0; i < this->room->getNrOfItems(); i++) {

		if (this->room->getItems()[i] != nullptr) {

			if (this->player->getBody().getGlobalBounds().intersects(this->room->getItems()[i]->getBody().getGlobalBounds())) {

				if (!this->player->fullInventory()) {

					delete this->room->getItems()[i];
					this->room->getItems()[i] = nullptr;
					this->player->addItemInInventory();


				}

			}

		}

	}

}

void GameHandler::updateSprites(float deltaTime) {

	this->room->updateSprites(deltaTime);

}

void GameHandler::detectKey(){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){

		if (!showMenu) {

			this->showMenu = true;

		}
		else {

			this->showMenu = false;

		}

		this->menuTimer = 0.0f;

	}

}

int GameHandler::update(float dt) {

	int gameOutput = 1;

	//Toggle Menu
	this->menuTimer += dt;
	if (this->menuTimer >= 0.25f) {

		this->detectKey();

	}

	if (this->showMenu) {

		//Update menu if it's open
		gameOutput = this->menu.detectKey(dt);

		if (gameOutput == 2) {

			this->reset();

		}

	}
	else{

		//Update player
		this->player->update(dt);

		//Update Sprite
		this->updateSprites(dt);

		//Check for collision with items
		this->itemCollision();

		//Update the players movement bounds
		this->updatePlayerBounds();

		//Check for collision with the portal
		if (this->updatePortalCollision()){

			this->player->newPosition(this->room->getRandomWalkableTile());

		}
	
	}

	return gameOutput;

}

void GameHandler::generateRoom()
{

	if (this->room != nullptr) {

		delete this->room;

	}

	//Create room
	this->room = new Room();

	//Set Tilemap
	this->tileMap = this->room->getTileMap();

}

void GameHandler::updatePlayerBounds() {

	//Update player indexed positon
	this->playerCurrentPos.x = ((this->player->getBody().getPosition().x + this->player->getBody().getGlobalBounds().width) / 64);
	this->playerCurrentPos.y = ((this->player->getBody().getPosition().y + this->player->getBody().getGlobalBounds().height) / 64);
	
	int left = (this->playerCurrentPos.x - 
		this->tileMap[this->playerCurrentPos.y][(this->playerCurrentPos.x - 1)]) * 64;

	int right = (this->playerCurrentPos.x +
		this->tileMap[this->playerCurrentPos.y][this->playerCurrentPos.x]) * 64;

	int top = (this->playerCurrentPos.y -
		this->tileMap[(this->playerCurrentPos.y - 1)][this->playerCurrentPos.x]) * 64;

	int bottom = (this->playerCurrentPos.y +
		this->tileMap[this->playerCurrentPos.y][this->playerCurrentPos.x]) * 64;

	this->player->updateMovementBounds(left, right, top, bottom);

}

#include "GameHandler.h"
#include <iostream>

GameHandler::GameHandler(){

	//Initialize values
	this->room = nullptr;
	this->player = nullptr;
	this->tileMap = nullptr;
	this->menuAnswer = 0;
	this->showMenu = false;

	//Generate Room 
	this->generateRoom();

	//Set startposition for player
	this->player = new Player(this->room->getRandomWalkableTile());

}

void GameHandler::reset(){

	//Delete room
	delete this->room;
	this->room = nullptr;

	//Create new player
	delete this->player;
	this->player = new Player(this->room->getRandomWalkableTile());

	//Generate room
	this->generateRoom();

}

void GameHandler::dueMenu(){

	if (this->menuAnswer != -1){

		if (this->menuAnswer){

			this->reset();
		
		}
		
		this->showMenu = false;
	
	}
}

void GameHandler::updatePortalCollision(){

	if (this->player->getBody().getGlobalBounds().intersects(this->room->getPortal().getGlobalBounds())){

		this->generateRoom();
	
	}

}

void GameHandler::draw(sf::RenderTarget &target, sf::RenderStates states) const{

	if (this->showMenu){

		target.draw(this->menu, states);
	
	}
	else{

		//target.draw(*this->player, states);
		target.draw(*this->room, states);
	
	}

}

void GameHandler::drawObjects(sf::RenderWindow& window) {

	window.draw(this->player->getBody());
	this->room->drawObjects(window);

}

void GameHandler::updateSprites(float deltaTime) {

	this->room->updateSprites(deltaTime);

}

void GameHandler::detectKey(){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !this->showMenu){

		//this->showMenu = true;

	}
}

void GameHandler::update(float dt)
{
	if (this->showMenu) {

		//Update menu if it's open
		this->menuAnswer = this->menu.update();

	}
	else{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {

			delete this->room;
			this->generateRoom();

		}

		//Open menu(Check for input)
		this->detectKey();

		//Update player
		this->player->update(dt);
		std::cout << "Player Pos: " << this->player->getBody().getPosition().x << " " << this->player->getBody().getPosition().y << std::endl;

		//Update the players movement bounds
		this->updatePlayerBounds();

		//Check for collision with the portal
		this->updatePortalCollision();

	}

}

void GameHandler::generateRoom(){

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

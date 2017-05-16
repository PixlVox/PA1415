#include "GameHandler.h"

void GameHandler::reset()
{
	this->currentRoom = 0;
	this->rooms.clear();
	this->player = Player();
	this->generateRoom();
	this->setPlayerPos();
}

void GameHandler::setPlayerPos()
{
	this->player.getBody().setPosition(this->rooms[this->currentRoom]->getRandomWalkableTile());
}

void GameHandler::dueMenu()
{
	if (this->menuAnswer != -1)
	{
		if (this->menuAnswer)
		{
			this->reset();
		}
		this->showMenu = false;
	}
}

void GameHandler::updatePortalCollision()
{
	if (this->rooms[this->currentRoom]->getPortal().getGlobalBounds().intersects(this->player.getBody().getGlobalBounds()))
	{
		this->generateRoom();
		this->currentRoom++;
	}
}

void GameHandler::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (this->showMenu)
	{
		target.draw(this->menu, states);
	}
	else
	{
		target.draw(this->player, states);
		target.draw(*this->rooms[this->currentRoom], states);
	}
}

void GameHandler::detectKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !this->showMenu)
	{
		this->showMenu = true;
	}
}

GameHandler::GameHandler()
{
	this->currentRoom = 0;
	this->menuAnswer = 0;
	this->showMenu = true;
	this->generateRoom();
	this->setPlayerPos();

}

void GameHandler::update(float dt)
{

	this->updatePlayerBounds();

	this->detectKey();
	this->player.update(dt);
	void updatePlayerBounds(void);
	this->updatePortalCollision();
	if (this->showMenu)
	{
		this-> menuAnswer =	this->menu.update();
	}
}

void GameHandler::generateRoom()
{

	//Create room
	this->rooms.push_back(new Room());

	//Set Tilemap
	this->tileMap = this->rooms[this->currentRoom]->getTileMap();
}

void GameHandler::updatePlayerBounds() {

	//Update player indexed positon
	this->playerCurrentPos.x = (this->player.getBody().getPosition().x / 64);
	this->playerCurrentPos.y = (this->player.getBody().getPosition().y / 64);
	
	int left = (this->playerCurrentPos.x - 
		this->tileMap[this->playerCurrentPos.x][this->playerCurrentPos.y]) * 64;

	int right = (this->playerCurrentPos.x +
		this->tileMap[this->playerCurrentPos.x][this->playerCurrentPos.y]) * 64;

	int top = (this->playerCurrentPos.y -
		this->tileMap[this->playerCurrentPos.x][this->playerCurrentPos.y]) * 64;

	int bottom = (this->playerCurrentPos.y +
		this->tileMap[this->playerCurrentPos.x][this->playerCurrentPos.y]) * 64;

	this->player.updateMovementBounds(left, right, top, bottom);

}

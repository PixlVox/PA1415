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

void GameHandler::dueMenu(int nr)
{
	if (nr != -1)
	{
		if (nr)
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
	this->tileMap = nullptr;
	this->currentRoom = 0;
	this->menuAnswer = 0;
	this->showMenu = false;
	this->menu = Menu();
	this->generateRoom();
	this->setPlayerPos();

}

void GameHandler::update(float dt)
{

	if (this->showMenu)
	{
		this->dueMenu(this->menu.update());
	}
	else
	{
		this->updatePlayerBounds();
		this->detectKey();
		this->player.update(dt);
		this->updatePortalCollision();
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

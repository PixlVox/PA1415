#include "GameHandler.h"

void GameHandler::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (this->showMenu)
	{
		target.draw(this->menu, states);
	}
	target.draw(this->player, states);
	target.draw(this->rooms[this->currentRoom]);
}

void GameHandler::detectKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !this->showMenu)
	{
		this->showMenu = true;
	}
	else if(this->showMenu)
	{
		this->showMenu = false;
	}
}

GameHandler::GameHandler()
{
	this->nrOfRooms = 0;
	this->currentRoom = 0;
	this->showMenu = true;
}

void GameHandler::update(float dt)
{
	this->detectKey();
	this->player.update(dt);
}

void GameHandler::generateRoom()
{
	this->rooms[this->nrOfRooms] = new Room();
	this->rooms[this->nrOfRooms]->createRoom();
	this->nrOfRooms++;
}

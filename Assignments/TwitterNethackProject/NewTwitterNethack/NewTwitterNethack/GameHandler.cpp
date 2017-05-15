#include "GameHandler.h"

void GameHandler::updatePortalCollision()
{
	this->rooms[this->currentRoom];
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
	else if(this->showMenu)
	{
		this->showMenu = false;
	}
}

GameHandler::GameHandler()
{
	this->nrOfRooms = 0;
	this->currentRoom = 0;
	this->menuAnswer = 0;
	this->showMenu = true;
	this->player = Player(sf::Vector2f(250, 250));
}

void GameHandler::update(float dt)
{
	this->detectKey();
	this->player.update(dt);
	if (this->showMenu)
	{
		this-> menuAnswer =	this->menu.update();
	}
}

void GameHandler::generateRoom()
{
	this->rooms[this->nrOfRooms] = new Room();
	this->rooms[this->nrOfRooms]->createRoom();
	this->nrOfRooms++;
}

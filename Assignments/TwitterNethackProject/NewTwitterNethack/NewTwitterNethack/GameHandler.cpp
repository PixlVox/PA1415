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
	this->detectKey();
	this->player.update(dt);
	this->updatePortalCollision();
	if (this->showMenu)
	{
		this-> menuAnswer =	this->menu.update();
	}
}

void GameHandler::generateRoom()
{
	this->rooms.push_back(new Room());
}

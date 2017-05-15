#include "Menu.h"

void Menu::updateHighlight()
{
	if (this->current == 0)
	{
		this->menuSprite[2].setPosition(sf::Vector2f(0, 0)); 
	}
	else
	{
		this->menuSprite[2].setPosition(sf::Vector2f(1, 1));
	}
}

int Menu::detectKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->current++;
		if (current > 1)
		{
			current = 0;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (current < 0)
		{
			current = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		this->done = this->current;
	}
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for each (sf::Sprite var in this->menuSprite)
	{
		target.draw(var, states);
	}
}

Menu::Menu()
{
	this->menuTexture.loadFromFile();
	this->menuSprite[0].setTexture(this->menuTexture);
	this->menuTexture.loadFromFile();
	this->menuSprite[1].setTexture(this->menuTexture);
	this->menuTexture.loadFromFile();
	this->menuSprite[2].setTexture(this->menuTexture);

	this->current = 0;
	this->done = -1;
}

int Menu::update()
{
	if (this->done != -1)
	{
		this->done = -1;
	}
	this->detectKey();
	this->updateHighlight();
	return this->done;
}

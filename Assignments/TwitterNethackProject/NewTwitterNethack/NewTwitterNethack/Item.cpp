#include "Item.h"

Item::Item() {

	//set Texture
	this->itemTexture.loadFromFile("Textures//Items//bathumball.png");
	this->itemSprite.setTexture(this->itemTexture);

	//set position
	this->xPos = 500.0f;
	this->yPos = 500.0f;
	this->itemSprite.setPosition(xPos, yPos);
}

Item::Item(float roomWidth, float roomHeight)
{
	//set Texture
	this->itemTexture.loadFromFile("Textures//Items//bathumball.png");
	this->itemSprite.setTexture(this->itemTexture);

	//set position
	this->xPos = roomWidth;
	this->yPos = roomHeight;
	this->itemSprite.setPosition(xPos, yPos);
}

Item::Item(float roomWidth, float roomHeight, bool isOnFloor)
{
	//set Texture
	this->itemTexture.loadFromFile("Textures//Items//bathumball.png");
	this->itemSprite.setTexture(this->itemTexture);

	//set position
	this->xPos = roomWidth;
	this->yPos = roomHeight;
	this->itemSprite.setPosition(xPos, yPos);

	//set properties
	this->isOnFloor = isOnFloor;
}

void Item::setPosition(float x, float y)
{
	this->itemSprite.setPosition(x, y);
}

void Item::setPosition(const sf::Vector2f position)
{
	this->itemSprite.setPosition(position);
}

sf::Vector2f Item::getPosition()
{
	return sf::Vector2f(this->itemSprite.getPosition());
}

void Item::setIsOnFloor(bool isOnFloor)
{
	this->isOnFloor = isOnFloor;
}

void Item::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->itemSprite, states);
}
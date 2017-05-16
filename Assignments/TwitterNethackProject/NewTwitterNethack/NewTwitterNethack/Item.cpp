#include "Item.h"

Item::Item() {

	//set Texture
	this->itemTexture.loadFromFile("Textures//Items//bathumball.png");
	this->itemSprite.setTexture(this->itemTexture);
	this->itemSprite.setPosition(sf::Vector2f(0.0f, 0.0f));

	//set position
	this->xPos = -100.0f;
	this->yPos = -100.0f;
	this->itemSprite.setPosition(xPos, yPos);
	this->itemSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

}

Item::Item(sf::Vector2f walkableTile){

	//set Texture
	this->itemTexture.loadFromFile("Textures//Items//bathumball.png");
	this->itemSprite.setTexture(this->itemTexture);

	//set position to the center of a walkable tile.
	this->xPos = walkableTile.x + 16;
	this->yPos = walkableTile.y + 16;
	this->itemSprite.setPosition(xPos, yPos);

}

Item::Item(sf::Vector2f walkableTile, bool isOnFloor){

	//set Texture
	this->itemTexture.loadFromFile("Textures//Items//bathumball.png");
	this->itemSprite.setTexture(this->itemTexture);

	//set position to the center of a walkable tile.
	this->xPos = walkableTile.x + 16;
	this->yPos = walkableTile.y + 16;
	this->itemSprite.setPosition(xPos, yPos);

}

void Item::setPosition(float x, float y){

	this->itemSprite.setPosition(x, y);

}

void Item::setPosition(sf::Vector2f position){

	this->itemSprite.setPosition(position);

}

sf::Vector2f Item::getPosition(){

	return sf::Vector2f(this->itemSprite.getPosition());

}

sf::Sprite Item::getBody(void) {

	return this->itemSprite;

}

void Item::setScale(sf::Vector2f scale) {

	this->itemSprite.setScale(scale);

}
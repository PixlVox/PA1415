#include "Item.h"

Item::Item() {

	//set Texture
	this->itemTexture.loadFromFile("Textures\Items\bathumball.png");
	this->itemSprite.setTexture(this->itemTexture);

	//set position
	this->xPos = 500;
	this->yPos = 500;
	this->itemSprite.setPosition(xPos, yPos);
}

void Item::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->itemSprite, states);
}
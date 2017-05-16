#include "Inventory.h"

Inventory::Inventory()
{
	//set Texture
	this->invTexture.loadFromFile("Textures//Items//inventory.png");
	this->invSprite.setTexture(this->invTexture);
	this->invSprite.setTextureRect(sf::IntRect(0, 0, 128, 384));

	//set position
	this->xPos = 32.0f;
	this->yPos = 32.0f;
	this->invSprite.setPosition(xPos, yPos);
}

void Inventory::update(float dt)
{

}

void Inventory::addItem(Item item)
{
	if (this->nrOfItems < 3) {
		this->items[this->nrOfItems] = item;
		this->items[this->nrOfItems].setIsOnFloor(false);
		this->items[this->nrOfItems].setPosition(64, 64 * this->nrOfItems);
		this->nrOfItems++;
	}
	else {
		//Inventory is full.
	}
}

void Inventory::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < this->nrOfItems; i++) {
		target.draw(this->items[i], states);
	}
}

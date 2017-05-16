#include "Inventory.h"

Inventory::Inventory(){

	//set Texture
	this->invTexture.loadFromFile("Textures//Items//inventory.png");
	this->invSprite.setTexture(this->invTexture);
	this->invSprite.setTextureRect(sf::IntRect(0, 0, 128, 384));

	//set position
	this->xPos = 32.0f;
	this->yPos = 32.0f;
	this->invSprite.setPosition(xPos, yPos);

}

void Inventory::update(float dt){



}

void Inventory::addItem(Item &item){

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

int Inventory::getNrOfItems()
{
	return this->nrOfItems;
}

void Inventory::emptyInventory()
{
	this->nrOfItems = 0;
}

sf::Sprite & Inventory::getItemBodies(int index)
{
	return this->items[index].getBody();
}

Item & Inventory::dropItem()
{
	if (this->nrOfItems > 0) {
		this->nrOfItems--;
		return this->items[this->nrOfItems - 1];
	}
	else {
		return Item();
	}
}

Item & Inventory::dropItem(int index)
{
	if (this->nrOfItems > index) {
		this->nrOfItems--;
		return this->items[index];
	}
	else {
		return Item();
	}
}

void Inventory::draw(sf::RenderTarget & target, sf::RenderStates states) const{

	target.draw(this->invSprite, states);

	for (int i = 0; i < this->nrOfItems; i++) {

		target.draw(this->items[i], states);
	
	}

}

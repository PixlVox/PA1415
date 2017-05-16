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

<<<<<<< HEAD
void Inventory::addItem(Item &item)
{
=======
void Inventory::addItem(Item item){

>>>>>>> 51feb0200b03ef062bab96b801a22cee27c3a5ff
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

<<<<<<< HEAD
int Inventory::getNrOfItems()
{
	return this->nrOfItems;
}

sf::Sprite & Inventory::getItemBodies(int index)
{
	return this->items[index].getBody();
}

void Inventory::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
=======
void Inventory::draw(sf::RenderTarget & target, sf::RenderStates states) const{

	target.draw(this->invSprite, states);

>>>>>>> 51feb0200b03ef062bab96b801a22cee27c3a5ff
	for (int i = 0; i < this->nrOfItems; i++) {

		target.draw(this->items[i], states);
	
	}

}

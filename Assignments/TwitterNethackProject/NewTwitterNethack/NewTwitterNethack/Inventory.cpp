#include "Inventory.h"

Inventory::Inventory(){

	//set Texture
	this->invTexture.loadFromFile("Textures//Items//inventory.png");
	this->invSprite.setTexture(this->invTexture);
	this->invSprite.setTextureRect(sf::IntRect(0, 0, 128, 384));

	this->items = new Item*[3];

	//set position
	this->xPos = 32.0f;
	this->yPos = 32.0f;
	this->invSprite.setPosition(xPos, yPos);

}

Inventory::~Inventory() {

	for (int i = 0; i < 3; i++) {

		if (this->items[i] != nullptr) {

			delete this->items[i];

		}

	}

	delete[] this->items;

}

void Inventory::addItem(){

	if (this->nrOfItems < 3) {

		this->items[this->nrOfItems] = new Item();
		this->items[this->nrOfItems]->setPosition(45, ((64 * (this->nrOfItems * 2)) + 50));
		this->items[this->nrOfItems]->setScale(sf::Vector2f(3.0f, 3.0f));
		this->nrOfItems++;

	}

}

int Inventory::getNrOfItems() const{
	
	return this->nrOfItems;

}

bool Inventory::isFull(void) const{

	return this->nrOfItems == 3;

}

void Inventory::dropItem(){

	if (this->nrOfItems > 0) {

		delete this->items[this->nrOfItems - 1];
		this->items[this->nrOfItems - 1] = nullptr;
		this->nrOfItems--;

	}

}

void Inventory::drawInventory(sf::RenderWindow& window) {

	window.draw(this->invSprite);
	
	for (int i = 0; i < this->nrOfItems; i++) {

		if (this->items[i] != nullptr) {

			window.draw(this->items[i]->getBody());

		}

	}

}

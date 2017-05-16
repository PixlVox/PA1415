#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

static const int inventory_space = 3;

class Inventory {

private:

	//Inventory slots
	sf::Sprite invSprite;
	sf::Texture invTexture;

	//Item Array
	Item** items;
	
	//Item variables
	int nrOfItems;
	float xPos;
	float yPos;

public:

	Inventory();
	~Inventory();

	void addItem();
	void dropItem();
	
	int getNrOfItems(void) const;
	bool isFull(void) const;

	void drawInventory(sf::RenderWindow& window);

};
#endif // !INVENTORY_H

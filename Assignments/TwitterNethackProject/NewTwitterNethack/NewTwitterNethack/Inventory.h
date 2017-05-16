#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

static const int inventory_space = 3;

class Inventory : sf::Drawable {

private:

	sf::Sprite invSprite;
	sf::Texture invTexture;
	Item items[inventory_space];
	int nrOfItems;
	float xPos;
	float yPos;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	Inventory();
	void update(float dt);
	void addItem(Item &item);
	
	int getNrOfItems();

	void emptyInventory();

	sf::Sprite& getItemBodies(int index);

	Item &dropItem();
	Item &dropItem(int index);

};
#endif // !INVENTORY_H

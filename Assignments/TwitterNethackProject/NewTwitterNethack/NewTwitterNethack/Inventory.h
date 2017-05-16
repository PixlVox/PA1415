#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
static const int inventory_space = 3;
class Inventory : sf::Drawable {
protected:
	sf::Sprite invSprite;
	sf::Texture invTexture;
	Item items[inventory_space];
	int nrOfItems;
	float xPos;
	float yPos;
public:
	Inventory();
	void update(float dt);
	void addItem(Item &item);
	int getNrOfItems();
	sf::Sprite& getItemBodies(int index);

	//Item& dropItem();
	//Item& dropItem(int index);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif // !INVENTORY_H

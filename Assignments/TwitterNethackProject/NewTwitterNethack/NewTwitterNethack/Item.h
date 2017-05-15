#ifndef ITEM_H
#define ITEM_H
#include "SFML\Graphics.hpp"
class Item : public sf::Drawable {
protected:

	sf::Sprite itemSprite;
	sf::Texture itemTexture;
<<<<<<< HEAD
	int xPos;
	int yPos;
=======
	sf::Vector2i position;
	
>>>>>>> fdb80812e0a57716e59d693f9053efb5cade78cc
	bool isOnFloor;

public:

	Item();
	Item(int roomWidth, int roomHeight);
	Item(int roomWidth, int roomHeight, bool isOnFloor);
	void setPosition(int x, int y);
	void setPosition(sf::Vector2i position);
	sf::Vector2i getPosition();
	int getX();
	int getY();
	void setIsOnFloor(bool isOnFloor);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif // !1

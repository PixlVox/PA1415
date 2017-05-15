#ifndef ITEM_H
#define ITEM_H
#include "SFML\Graphics.hpp"
class Item : public sf::Drawable {
protected:
	sf::Sprite itemSprite;
	sf::Texture itemTexture;
	sf::Vector2i position;
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

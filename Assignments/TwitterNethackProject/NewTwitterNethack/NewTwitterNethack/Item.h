#ifndef ITEM_H
#define ITEM_H
#include "SFML\Graphics.hpp"
class Item : public sf::Drawable {
protected:

	sf::Sprite itemSprite;
	sf::Texture itemTexture;
	float xPos;
	float yPos;
	bool isOnFloor;

public:

	Item();
	Item(float roomWidth, float roomHeight);
	Item(float roomWidth, float roomHeight, bool isOnFloor);
	void setPosition(float x, float y);
	void setPosition(const sf::Vector2f position);
	sf::Vector2f getPosition();
	void setIsOnFloor(bool isOnFloor);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif // !1

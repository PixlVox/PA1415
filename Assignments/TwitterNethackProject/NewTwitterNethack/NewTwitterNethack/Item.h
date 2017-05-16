#ifndef ITEM_H
#define ITEM_H

#include "SFML\Graphics.hpp"
#include <string>

class Item : public sf::Drawable {
protected:

	sf::Sprite itemSprite;
	sf::Texture itemTexture;
	float xPos;
	float yPos;
	bool isOnFloor;
	std::string description;

public:

	Item();
	Item(sf::Vector2f walkableTile);
	Item(sf::Vector2f walkableTile, bool isOnFloor);
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setIsOnFloor(bool isOnFloor);
	sf::Sprite getBody(void);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif // !1
#ifndef ITEM_H
#define ITEM_H

#include "SFML\Graphics.hpp"
#include <string>

class Item {

protected:

	sf::Sprite itemSprite;
	sf::Texture itemTexture;
	float xPos;
	float yPos;
	std::string description;

public:

	Item();
	Item(sf::Vector2f walkableTile);
	Item(sf::Vector2f walkableTile, bool isOnFloor);

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f position);
	void setScale(sf::Vector2f scale);

	sf::Vector2f getPosition();
	sf::Sprite getBody(void);

};
#endif // !1
#ifndef PLAYER_H
#define PLAYER_H
#include"Inventory.h"
#include"SFML\Graphics.hpp"

class Player : public sf::Drawable
{
private:

	//Texture stuff
	sf::Texture texture;
	sf::Sprite spriteSheet;
	int spriteSheetWidth;

	//Inventory stuff
	Inventory inventory;

	//Player movement
	sf::Vector2f velocity;
	float speed = 180.0f;
	int movementBoundLeft;
	int movementBoundRight;
	int movementBoundDown;
	int movementBoundUp;
	
	//Animation variables
	float animationSpeed;
	float keyFrameDuration;
	sf::Vector2i currentKeyFrame;
	sf::Vector2i keyFrameSize;

	//self explanatory
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	Player(sf::Vector2f pos);

	//Get
	sf::Sprite &getBody(void);

	//Inventory
	Inventory &getPlayerInventory();
	void addItemInInventory(Item &item);
	Item& dropItemFromInventory();
	Item& dropItemFromInventory(int index);

	//Set
	void newPosition(sf::Vector2f pos);

	//Update
	void update(float dt);
	void updateMovementBounds(int left, int right, int top, int bottom);

};
#endif // !PLAYER_H


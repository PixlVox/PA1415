#ifndef PLAYER_H
#define PLAYER_H

#include"SFML\Graphics.hpp"

class Player : public sf::Drawable
{
private:

	//Texture stuff
	sf::Texture texture;
	sf::Sprite spriteSheet;
	int spriteSheetWidth;

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
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Player();
	Player(sf::Vector2f pos);

	//Get
	sf::Sprite& getBody(void);

	//Update
	void update(float dt);
	void updateMovementBounds(int left, int right, int top, int bottom);

};
#endif // !PLAYER_H


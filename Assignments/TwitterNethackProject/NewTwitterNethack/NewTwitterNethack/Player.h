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

	void update(float dt);

};
#endif // !PLAYER_H


#ifndef PLAYER_H
#define PLAYER_H
#include"SFML\Graphics.hpp"

class Player
{
private:
	//Texture stuff
	sf::Texture texture;
	sf::Sprite spriteSheet;
	int spriteSheetWidth;

	//Player movement
	sf::Vector2f velocity;

	//Animation variables
	float animationSpeed;
	float keyFrameDuration;
	sf::Vector2i currentKeyFrame;
	sf::Vector2i keyFrameSize;

	//self explanatory
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Player(sf::Vector2f pos);

	void update(float dt);

};
#endif // !PLAYER_H
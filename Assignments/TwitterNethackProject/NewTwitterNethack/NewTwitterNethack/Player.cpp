#include "Player.h"
#include<iostream>

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(spriteSheet, states);
}
Player::Player(sf::Vector2f pos)
{
	//character sprite location
	sf::String fileName = "../NewTwitterNethack/Textures/Characters/player1.png";

	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (!texture.loadFromFile(fileName))
	{
		// Handle error: Print error message.
		std::cout << "ERROR: Player image could not be loaded.\n---" << std::endl;
	}
	spriteSheet.setTexture(texture);
	spriteSheet.setTextureRect(sf::IntRect(0, 0, 32, 32));

	currentKeyFrame = sf::Vector2i(0, 0);
	keyFrameSize = sf::Vector2i(32, 32);
	spriteSheet.setPosition(pos);
	spriteSheetWidth = 4;
	animationSpeed = 0.2f;
	keyFrameDuration = 0.0f;
}

void Player::update(float dt)
{
	// Handle input from arrow keys and update direction and animation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -1.0f;
		keyFrameDuration += dt;
		currentKeyFrame.y = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = 1.0f;
		keyFrameDuration += dt;
		currentKeyFrame.y = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y = 1.0f;
		keyFrameDuration += dt;
		currentKeyFrame.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y = -1.0f;
		keyFrameDuration += dt;
		currentKeyFrame.y = 3;
	}
	else {

		velocity.y = 0;
		velocity.x = 0;

	}
	spriteSheet.move(velocity * speed* dt);

	if (keyFrameDuration >= animationSpeed)
	{
		currentKeyFrame.x++;

		if (currentKeyFrame.x >= spriteSheetWidth)
			currentKeyFrame.x = 0;

		spriteSheet.setTextureRect(sf::IntRect(currentKeyFrame.x * keyFrameSize.x,
			currentKeyFrame.y * keyFrameSize.y, keyFrameSize.x, keyFrameSize.y));
		keyFrameDuration = 0.0f;
	}
}

sf::Sprite& Player::getBody(void) {

	return this->spriteSheet;

}

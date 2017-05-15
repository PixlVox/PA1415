#ifndef PORTAL_H
#define PORTAL_H

#include"SFML\Graphics.hpp"

class Portal {

private:

	//Portal
	sf::RectangleShape body;
	sf::Texture texture;
	
	//Animation
	float timer;
	int nrOfFramesX;
	int currentFrameX;

public:

	Portal(sf::Vector2f pos);
	~Portal();

	//Get
	sf::RectangleShape getBody(void);

	//Update
	void updateAnimation(float deltaTime);

};

#endif // !PORTAL_H

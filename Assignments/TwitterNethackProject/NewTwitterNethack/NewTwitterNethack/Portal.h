#ifndef PORTAL_H
#define PORTAL_H

#include"SFML\Graphics.hpp"

class Portal {

private:

	sf::RectangleShape body;
	sf::Texture texture;

	float timer;
	int nrOfFramesX;
	int currentFrameX;

public:

	Portal(int x, int y);
	~Portal();

	sf::RectangleShape getBody(void);

	void updateAnimation(float deltaTime);

};

#endif // !PORTAL_H

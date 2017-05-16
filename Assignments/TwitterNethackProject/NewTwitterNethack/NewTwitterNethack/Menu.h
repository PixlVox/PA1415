#ifndef MENU_H
#define MENU_H

#include<SFML\Graphics.hpp>

class Menu {

private:

	sf::Texture exitTexture;
	sf::Texture startTexture;
	sf::Texture highlightTexture;
	sf::Sprite menuSprite[3];
	int current;
	float menuTimer;

	sf::RectangleShape transparency;

public:

	Menu();

	int detectKey(float deltaTime);

	void drawButtons(sf::RenderWindow& window);

};
#endif // !MENU_H

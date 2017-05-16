#ifndef MENU_H
#define MENU_H

#include<SFML\Graphics.hpp>

class Menu : public sf::Drawable
{
private:
	sf::Texture menuTexture;
	sf::Sprite menuSprite[2];
	sf::RectangleShape background;
	int current;
	int done;

	void detectKey();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
protected:


public:
	Menu();
	int update();

};
#endif // !MENU_H

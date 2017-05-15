#ifndef PLAYER_H
#define PLAYER_H
#include"SFML\Graphics.hpp"

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Player(sf::Vector2f pos);

	void update();

};
#endif // !PLAYER_H
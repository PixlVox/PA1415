#ifndef PLAYER_H
#define PLAYER_H
<<<<<<< HEAD
=======
#include"SFML\Graphics.hpp"
>>>>>>> fb8f51b831f84ca34855755a53638a6ed50bcb59

class Player
{
private:
<<<<<<< HEAD



protected:


public:

}

#endif // !PLAYER_H
=======
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Player(sf::Vector2f pos);

	void update();

};
#endif // !PLAYER_H
>>>>>>> fb8f51b831f84ca34855755a53638a6ed50bcb59

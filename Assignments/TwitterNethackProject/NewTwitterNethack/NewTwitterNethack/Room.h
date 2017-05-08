#ifndef ROOM_H
#define ROOM_H

#include "SFML\Graphics.hpp"

class Room : public sf::Drawable, public sf::Transformable{

private:

	sf::VertexArray vertices;
	sf::Texture texture;
	int* tiles;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	Room();
	~Room();

	void generateTiles(void);
	void loadVertexArray(void);

};

#endif // !ROOM_H


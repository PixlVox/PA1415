#ifndef ROOM_H
#define ROOM_H

#include "SFML\Graphics.hpp"
#include <iostream>
#include <fstream>
#include <string>

class Room : public sf::Drawable, public sf::Transformable{

private:

	//Graphics
	sf::VertexArray vertices;
	sf::Texture texture;
	
	//Tiles Texture Coords
	sf::Vector2i** tilesTextureCoords;
	std::string textureCoordsLine;
	std::ifstream inFile;

	//Tiles values
	sf::Vector2i nrOfTiles;
	sf::Vector2i tileSize;

	//Tiles collision array
	int** tilesCollision;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	Room();
	~Room();

	void generateTiles(void);
	void loadVertexArray(void);

};

#endif // !ROOM_H


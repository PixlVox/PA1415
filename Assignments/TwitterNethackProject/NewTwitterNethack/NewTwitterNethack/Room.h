#ifndef ROOM_H
#define ROOM_H

#include "SFML\Graphics.hpp"
#include <string>
#include <fstream>

class Room : public sf::Drawable, public sf::Transformable{

private:

	//Graphics
	sf::VertexArray vertices;
	sf::Texture texture;
	int textureType;
	
	//Tiles / Texture Coords
	int** tiles;
	std::string textureCoordsLine;
	std::ifstream inFile;
	int roomLayout;

	//Tiles values
	sf::Vector2i nrOfTiles;
	sf::Vector2i tileSize;

	//Private functions
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void calculateTexture();
	void calculateLayout(void);
	void generateTiles(void);
	void loadVertexArray(void);

public:

	Room();
	~Room();

	//Get
	int** getTileMap(void);

	//Misc
	void createRoom(void);

};

#endif // !ROOM_H


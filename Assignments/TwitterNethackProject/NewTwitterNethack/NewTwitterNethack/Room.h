#ifndef ROOM_H
#define ROOM_H

<<<<<<< HEAD
#include "SFML\Graphics.hpp"
#include <iostream>
#include <fstream>
#include <string>
=======
#include"Portal.h"
#include"Item.h"
#include<string>
#include<fstream>
>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109

class Room : public sf::Drawable, public sf::Transformable{

private:

	//Graphics
	sf::VertexArray vertices;
	sf::Texture texture;
<<<<<<< HEAD
	
	//Tiles Texture Coords
	sf::Vector2i** tilesTextureCoords;
	std::string textureCoordsLine;
	std::ifstream inFile;

	//Tiles values
	sf::Vector2i nrOfTiles;
	sf::Vector2i tileSize;

	//Tiles collision array
	int** tilesCollision;
=======
	int textureType;
	
	//Tiles / Texture Coords
	int** tiles;
	std::string textureCoordsLine;
	std::ifstream inFile;
	int roomLayout;
>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109

	//Tiles values
	sf::Vector2i nrOfTiles;
	sf::Vector2i tileSize;

	//Obligatory Object
	Portal* portal;
	Item* items;

	//Private functions
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//Calls on every other setup function(private functions below)
	void createRoom(void);

	void calculateTexture();
	void calculateLayout(void);
	void generateTiles(void);
	void loadVertexArray(void);
	void setupPortal(void);
	void generateItems(void);

public:

	Room();
	~Room();

	//Get
	int** getTileMap(void);
	sf::Vector2i getNrOfTiles(void);
	sf::Vector2f getRandomWalkableTile(void);
	sf::RectangleShape getPortal(void);

	//Update
	void updateSprites(float deltaTime);

	//Misc
	void drawObjects(sf::RenderWindow& window);

};

#endif // !ROOM_H


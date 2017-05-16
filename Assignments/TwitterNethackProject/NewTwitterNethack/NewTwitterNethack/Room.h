#ifndef ROOM_H
#define ROOM_H

#include"Portal.h"
#include"Item.h"
#include<string>
#include<fstream>

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

	//Objects
	Portal* portal;
	Item* items;

	//Item Varaibles
	int nrOfItems;

	//Private functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

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
	int** getTileMap(void) const;
	sf::Vector2i getNrOfTiles(void) const;
	sf::Vector2f getRandomWalkableTile(void) const;
	sf::RectangleShape getPortal(void) const;
	sf::Vector2i getTileSize(void) const;

	//Update
	void updateSprites(float deltaTime);

	//Misc
	void drawObjects(sf::RenderWindow& window);

};

#endif // !ROOM_H


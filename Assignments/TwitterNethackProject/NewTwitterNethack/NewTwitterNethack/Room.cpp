#include "Room.h"
#include <iostream>

Room::Room() {

<<<<<<< HEAD
	this->tilesTextureCoords = nullptr;
	this->tilesCollision = nullptr;

	this->nrOfTiles = sf::Vector2i(30, 17);
	this->tileSize = sf::Vector2i(64, 64);

	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize((this->tileSize.x * this->tileSize.y) * 4);

	this->texture.loadFromFile("Textures//Tiles//Tiles_64x64.png");
=======
	srand(static_cast<unsigned>(time(0)));

	//Tiles
	this->nrOfTiles = sf::Vector2i(30, 17);
	this->tileSize = sf::Vector2i(64, 64);
	this->roomLayout = 0;
	this->textureType = 0;
	this->tiles = nullptr;

	//Vertex Array Setup
	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize((this->tileSize.x * this->tileSize.y) * 4);

	//Room Objects
	this->portal = nullptr;
	this->items = nullptr;

	this->createRoom();
>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109

}

Room::~Room() {

	for (int i = 0; i < this->nrOfTiles.y; i++) {

<<<<<<< HEAD
		delete[] this->tilesTextureCoords[i];

	}

	delete[] this->tilesTextureCoords;

	for (int i = 0; i < this->nrOfTiles.y; i++) {

		delete[] this->tilesCollision[i];

	}

	delete[] this->tilesCollision;
=======
		delete[] this->tiles[i];

	}

	delete[] this->tiles;

	delete this->portal;

}

void Room::calculateTexture(void) {

	this->textureType = rand() % 2 + 0;
	this->texture.loadFromFile("Textures//Tiles//Tiles_" + std::to_string(this->textureType) + ".png");

}

void Room::calculateLayout() {

	this->roomLayout = rand() % 10 + 0;
>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109

}

void Room::generateTiles() {

<<<<<<< HEAD
	this->inFile.open("Rooms//Room_0.txt");

	if (this->tilesTextureCoords == nullptr) {

		this->tilesTextureCoords = new sf::Vector2i*[this->nrOfTiles.y];

		for (int i = 0; i < this->nrOfTiles.y; i++) {

			this->tilesTextureCoords[i] = new sf::Vector2i[this->nrOfTiles.x];

		}

		int strIndex = 0;

		for (int row = 0; row < this->nrOfTiles.y; row++) {

			std::getline(this->inFile, this->textureCoordsLine);
			std::ignore;

			for (int col = 0; col < this->nrOfTiles.x; col++) {
				
				this->tilesTextureCoords[row][col] = sf::Vector2i((static_cast<int>(this->textureCoordsLine.at(strIndex)) - 48),
					(static_cast<int>(this->textureCoordsLine.at(strIndex + 2)) - 48));
				strIndex += 4;

			}

			strIndex = 0;
			this->textureCoordsLine = "";

		}

=======
	this->inFile.open("Rooms//Room_" + std::to_string(this->roomLayout) + ".txt");

	//Create tiles
	this->tiles = new int*[this->nrOfTiles.y];

	for (int i = 0; i < this->nrOfTiles.y; i++) {

		this->tiles[i] = new int[this->nrOfTiles.x];

	}

	//Load tiles from text file
	int strIndex = 0;
	for (int i = 0; i < this->nrOfTiles.y; i++) {

		std::getline(this->inFile, this->textureCoordsLine);
		std::ignore;

		for (int j = 0; j < this->nrOfTiles.x; j++) {
				
			this->tiles[i][j] = ((static_cast<int>(this->textureCoordsLine.at(strIndex)) - 48));
			strIndex += 2;

		}

		strIndex = 0;
		this->textureCoordsLine = "";

>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109
	}

	this->inFile.close();

}

void Room::loadVertexArray(void) {

<<<<<<< HEAD
=======
	//Setup VertexArray
>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109
	for (int i = 0; i < this->nrOfTiles.y; i++) {

		for (int j = 0; j < this->nrOfTiles.x; j++) {

			sf::Vertex* quad = &this->vertices[(j + (i * this->nrOfTiles.x)) * 4];

			//Position
			quad[0].position = sf::Vector2f((j * this->tileSize.x), ((i + 1) * this->tileSize.y));
			quad[1].position = sf::Vector2f((j * this->tileSize.x), (i * this->tileSize.y));
			quad[2].position = sf::Vector2f(((j + 1) * this->tileSize.x), (i * this->tileSize.y));
			quad[3].position = sf::Vector2f(((j + 1) * this->tileSize.x), ((i + 1) * this->tileSize.y));

<<<<<<< HEAD
			//Texture Coords
			quad[0].texCoords = sf::Vector2f((this->tilesTextureCoords[i][j].x * this->tileSize.x),
				((this->tilesTextureCoords[i][j].y + 1) * this->tileSize.y));

			quad[1].texCoords = sf::Vector2f((this->tilesTextureCoords[i][j].x * this->tileSize.x),
				(this->tilesTextureCoords[i][j].y  * this->tileSize.y));

			quad[2].texCoords = sf::Vector2f(((this->tilesTextureCoords[i][j].x + 1) * this->tileSize.x),
				(this->tilesTextureCoords[i][j].y  * this->tileSize.y));

			quad[3].texCoords = sf::Vector2f(((this->tilesTextureCoords[i][j].x + 1) * this->tileSize.x),
				((this->tilesTextureCoords[i][j].y + 1) * this->tileSize.y));

		}

	}
=======
			int textureX = rand() % 4 + 0;
			int textureY = this->tiles[i][j];

			//Texture Coords
			quad[0].texCoords = sf::Vector2f((textureX * this->tileSize.x), ((textureY + 1) * tileSize.y));
			quad[1].texCoords = sf::Vector2f((textureX * this->tileSize.x), (textureY * tileSize.y));
			quad[2].texCoords = sf::Vector2f(((textureX + 1) * this->tileSize.x), (textureY * tileSize.y));
			quad[3].texCoords = sf::Vector2f(((textureX + 1) * this->tileSize.x), ((textureY + 1) * tileSize.y));

		}

	}

}

void Room::setupPortal(void) {

	portal = new Portal(this->getRandomWalkableTile());

}

void Room::generateItems(void) {



}

void Room::createRoom(void) {

	this->calculateTexture();
	this->calculateLayout();
	this->generateTiles();
	this->loadVertexArray();
	this->setupPortal();

}

void Room::updateSprites(float deltaTime) {

	portal->updateAnimation(deltaTime);
>>>>>>> 7b962871ece929bca3fc06326c98d764d8a13109

}

void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	states.transform *= this->getTransform();

	states.texture = &this->texture;

	target.draw(this->vertices, states);

}

void Room::drawObjects(sf::RenderWindow& window) {

	window.draw(this->portal->getBody());

}

sf::Vector2f Room::getRandomWalkableTile(void) {

	//Find walkable tile
	int tileX = rand() % 30 + 0;
	int tileY = rand() % 17 + 0;

	while (this->tiles[tileY][tileX] != 1) {

		tileX = rand() % 30 + 0;
		tileY = rand() % 17 + 0;

	}

	tileX *= 64;
	tileY *= 64;

	return sf::Vector2f(tileX, tileY);

}

int** Room::getTileMap(void) {

	return this->tiles;

}

sf::Vector2i Room::getNrOfTiles(void) {

	return this->nrOfTiles;

}

sf::RectangleShape Room::getPortal(void) {

	return this->portal->getBody();

}
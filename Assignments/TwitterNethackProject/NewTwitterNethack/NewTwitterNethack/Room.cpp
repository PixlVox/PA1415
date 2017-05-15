#include "Room.h"
#include <iostream>

Room::Room() {

	srand(static_cast<unsigned>(time(0)));

	this->nrOfTiles = sf::Vector2i(30, 17);
	this->tileSize = sf::Vector2i(64, 64);
	this->roomLayout = 0;

	this->tiles = nullptr;

	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize((this->tileSize.x * this->tileSize.y) * 4);

	this->textureType = 0;

}

Room::~Room() {

	for (int i = 0; i < this->nrOfTiles.y; i++) {

		delete[] this->tiles[i];

	}

	delete[] this->tiles;

}

void Room::calculateTexture(void) {

	this->textureType = rand() % 2 + 0;

	this->texture.loadFromFile("Textures//Tiles//Tiles_" + std::to_string(this->textureType) + ".png");

}

void Room::calculateLayout() {

	this->roomLayout = rand() % 10 + 0;

}

void Room::generateTiles() {

	this->inFile.open("Rooms//Room_" + std::to_string(this->roomLayout) + ".txt");

	this->tiles = new int*[this->nrOfTiles.y];

	for (int i = 0; i < this->nrOfTiles.y; i++) {

		this->tiles[i] = new int[this->nrOfTiles.x];

	}

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

	}

	this->inFile.close();

}

void Room::loadVertexArray(void) {

	for (int i = 0; i < this->nrOfTiles.y; i++) {

		for (int j = 0; j < this->nrOfTiles.x; j++) {

			sf::Vertex* quad = &this->vertices[(j + (i * this->nrOfTiles.x)) * 4];

			//Position
			quad[0].position = sf::Vector2f((j * this->tileSize.x), ((i + 1) * this->tileSize.y));
			quad[1].position = sf::Vector2f((j * this->tileSize.x), (i * this->tileSize.y));
			quad[2].position = sf::Vector2f(((j + 1) * this->tileSize.x), (i * this->tileSize.y));
			quad[3].position = sf::Vector2f(((j + 1) * this->tileSize.x), ((i + 1) * this->tileSize.y));

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

void Room::createRoom(void) {

	this->calculateTexture();
	this->calculateLayout();
	this->generateTiles();
	this->loadVertexArray();

}

void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	states.transform *= this->getTransform();

	states.texture = &this->texture;

	target.draw(this->vertices, states);

}

int** Room::getTileMap(void) {

	return this->tiles;

}
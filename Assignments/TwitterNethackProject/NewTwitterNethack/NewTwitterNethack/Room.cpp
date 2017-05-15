#include "Room.h"

Room::Room() {

	this->tilesTextureCoords = nullptr;
	this->tilesCollision = nullptr;

	this->nrOfTiles = sf::Vector2i(30, 17);
	this->tileSize = sf::Vector2i(64, 64);

	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize((this->tileSize.x * this->tileSize.y) * 4);

	this->texture.loadFromFile("Textures//Tiles//Tiles_64x64.png");

}

Room::~Room() {

	for (int i = 0; i < this->nrOfTiles.y; i++) {

		delete[] this->tilesTextureCoords[i];

	}

	delete[] this->tilesTextureCoords;

	for (int i = 0; i < this->nrOfTiles.y; i++) {

		delete[] this->tilesCollision[i];

	}

	delete[] this->tilesCollision;

}

void Room::generateTiles() {

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

}

void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	states.transform *= this->getTransform();

	states.texture = &this->texture;

	target.draw(this->vertices, states);

}
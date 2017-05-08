#include "Room.h"

Room::Room() {



}

Room::~Room() {



}

void Room::generateTiles() {



}

void Room::loadVertexArray(void) {

	

}

void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	states.transform *= this->getTransform();

	states.texture = &this->texture;

	target.draw(this->vertices, states);

}
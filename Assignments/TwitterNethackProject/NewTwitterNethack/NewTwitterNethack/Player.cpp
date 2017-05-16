#include "Player.h"

Player::Player(sf::Vector2f pos){

	//character sprite location
	sf::String fileName = "../NewTwitterNethack/Textures/Characters/player1.png";
	this->texture.loadFromFile(fileName);

	this->spriteSheet.setTexture(texture);
	this->spriteSheet.setTextureRect(sf::IntRect(0, 0, 32, 32));

	this->currentKeyFrame = sf::Vector2i(0, 0);
	this->keyFrameSize = sf::Vector2i(32, 32);
	this->spriteSheet.setPosition(pos);
	this->spriteSheetWidth = 4;
	this->animationSpeed = 0.2f;
	this->keyFrameDuration = 0.0f;

	this->movementBoundDown = 0;
	this->movementBoundLeft = 0;
	this->movementBoundRight = 0;
	this->movementBoundUp = 0;

	this->dropTimer = 0.0f;

}

void Player::update(float dt){
	
	this->velocity.x = 0.0f;
	this->velocity.y = 0.0f;

	bool moving = false;

	// Handle input from arrow keys and update direction and animation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		&& this->spriteSheet.getPosition().x > this->movementBoundLeft){

		velocity.x = -1.0f;
		keyFrameDuration += dt;
		currentKeyFrame.y = 1;
		moving = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
		&& (this->spriteSheet.getPosition().x + this->spriteSheet.getGlobalBounds().width)
		< this->movementBoundRight){

		velocity.x = 1.0f;
		keyFrameDuration += dt;
		currentKeyFrame.y = 2;
		moving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		&& (this->spriteSheet.getPosition().y + this->spriteSheet.getGlobalBounds().height)
		< this->movementBoundDown){

		velocity.y = 1.0f;
		keyFrameDuration += dt;
		currentKeyFrame.y = 0;
		moving = true;
	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		&& this->spriteSheet.getPosition().y > this->movementBoundUp){

		velocity.y = -1.0f;
		keyFrameDuration += dt;
		currentKeyFrame.y = 3;
		moving = true;
	}

	if (!moving){

		this->velocity.x = 0.0f;
		this->velocity.y = 0.0f;
	}
	
	this->spriteSheet.move(this->velocity * this->speed* dt);

	//Animation stuff
	if (this->keyFrameDuration >= this->animationSpeed) {

		this->currentKeyFrame.x++;

		if (this->currentKeyFrame.x >= this->spriteSheetWidth) {

			this->currentKeyFrame.x = 0;

		}

		this->spriteSheet.setTextureRect(sf::IntRect((this->currentKeyFrame.x * this->keyFrameSize.x),
			(this->currentKeyFrame.y * this->keyFrameSize.y), this->keyFrameSize.x, this->keyFrameSize.y));

		this->keyFrameDuration = 0.0f;

	}

	//Drop Item
	this->dropItemFromInventory(dt);

}

void Player::updateMovementBounds(int left, int right, int top, int bottom) {

	this->movementBoundLeft = left;
	this->movementBoundRight = right;
	this->movementBoundUp = top;
	this->movementBoundDown = bottom;

}

sf::Sprite Player::getBody(void) {

	return this->spriteSheet;

}

void Player::addItemInInventory(){

	this->inventory.addItem();

}

bool Player::fullInventory(void) const{

	return this->inventory.isFull();

}

void Player::dropItemFromInventory(float deltaTime) {

	this->dropTimer += deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {

		if (this->dropTimer >= 0.2f) {

			this->inventory.dropItem();
			this->dropTimer = 0.0f;

		}

	}

}

void Player::newPosition(sf::Vector2f pos) {

	this->spriteSheet.setPosition(pos);

}

void Player::drawPlayerAndInventory(sf::RenderWindow& window) {

	this->inventory.drawInventory(window);
	window.draw(this->spriteSheet);

}

#ifndef GameHandler_H
#define GameHandler_H

#include"Room.h"
#include"Player.h"
#include "Item.h"
#include"Menu.h"

class GameHandler : public sf::Drawable
{

private:

	Room* room;
	Player* player;
	Menu menu;

<<<<<<< HEAD
	//Item/Inventory
	Item bitchBall;

	int currentRoom;
=======
>>>>>>> 1f01b70561d2df786db3653f4c6c8cab082777ab
	sf::Vector2i playerCurrentPos;
	int** tileMap;
	bool showMenu;
	int menuAnswer;

	//Private functions
	void reset();
<<<<<<< HEAD

	void dueMenu(int nr);

	void updatePortalCollision();
=======
	void dueMenu();
	bool updatePortalCollision();
>>>>>>> 2fb162709a996192a6a0bccf78c8176946b9f88a
	void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void detectKey();
	void updatePlayerBounds(void);
	void generateRoom();

public:

	GameHandler();

	//Update
	void update(float dt);
	void updateSprites(float deltaTime);

	//Draw
	void drawObjects(sf::RenderWindow& window);


};
#endif // !GameHandler.h

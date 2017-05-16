#ifndef GameHandler_H
#define GameHandler_H

#include"Room.h"
#include"Player.h"
#include"Menu.h"

class GameHandler : public sf::Drawable
{

private:

	Room* room;
	Player* player;
	Menu menu;

	sf::Vector2i playerCurrentPos;
	int** tileMap;
	bool showMenu;
	int menuAnswer;

	//Private functions
	void reset();
	void dueMenu();
	bool updatePortalCollision();
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

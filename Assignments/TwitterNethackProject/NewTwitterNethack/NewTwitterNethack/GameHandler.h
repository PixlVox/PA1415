#ifndef GameHandler_H
#define GameHandler_H
#include<vector>
#include"Room.h"
#include"Player.h"
#include"Menu.h"

class GameHandler : public sf::Drawable
{

private:

	std::vector<Room*> rooms;
	Player player;
	Menu menu;

	int currentRoom;
	sf::Vector2i playerCurrentPos;
	int** tileMap;
	bool showMenu;
	int menuAnswer;

	//Private functions
	void reset();
	void setPlayerPos();
	void dueMenu(int nr);
	void updatePortalCollision();
	void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void detectKey();
	void updatePlayerBounds(void);
	void generateRoom();

protected:


public:

	GameHandler();
	void update(float dt);


};
#endif // !GameHandler.h

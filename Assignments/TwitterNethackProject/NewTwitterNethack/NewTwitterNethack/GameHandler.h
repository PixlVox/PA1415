#ifndef GameHandler_H
#define GameHandler_H
#include<vector>
#include"Room.h"
#include"Player.h"
#include "Item.h"
#include"Menu.h"

class GameHandler : public sf::Drawable
{

private:
	std::vector<Room*> rooms;
	Player player;
	Menu menu;

	//Item/Inventory
	Item bitchBall;

	int currentRoom;
	sf::Vector2f plOrigPos;
	bool showMenu;
	int menuAnswer;

	void reset();
	void setPlayerPos();
	void dueMenu();
	void updatePortalCollision();
	void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void detectKey();

protected:


public:
	GameHandler();
	void update(float dt);
	void generateRoom();




};
#endif // !GameHandler.h

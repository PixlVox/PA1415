#ifndef GameHandler_H
#define GameHandler_H
#include<vector>
#include"Room.h"
#include"Player.h"
#include"Menu.h"

class GameHandler
{

private:
	std::vector<Room*> rooms;
	Room *roomPtr;
	Player player;
	Menu menu;
	int nrOfRooms;

protected:


public:
	GameHandler();

	void generateRoom();




};
#endif // !GameHandler.h

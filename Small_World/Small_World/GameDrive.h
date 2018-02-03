#include "Player.h"
#include "Map.h"

#ifndef GAMEDRIVE_H
#define GAMEDRIVE_H

class GameDrive {
private:
	int numOfPlayer;
	int numOfTurn;
public:
	GameDrive();
	//load map and number of player
	//GameDrive(map, int);
	~GameDrive();
	void start();
};


#endif

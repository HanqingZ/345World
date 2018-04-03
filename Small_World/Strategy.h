#ifndef STRATEGY_H
#define STRATEGY_H

#include "Player.h"
//#include "AI.h"
#include "MapLoader.h"
#include "Dice.h"
#include <vector>
#include <string>
#include <list>

using namespace std;

class Strategy {
public:
	Strategy() {}
	//int getPlayerType();
	virtual void execute(MapLoader&, Player*);
	virtual void pick_race(MapLoader&, Player*) {}
	virtual void conquers(MapLoader&, Player*) {}
	virtual void redeployment(MapLoader&, Player*) {}
	virtual void score(MapLoader&, Player*) {}
	virtual void chooseDecline(Player*) {}
};

#endif
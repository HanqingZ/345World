#ifndef STRATEGY_H
#define STRATEGY_H

#include "Player.h"
#include "AI.h"
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
	virtual void execute(MapLoader&, Player*, vector<Player>&, int) {}
	virtual void abandon(MapLoader&, Player*, vector<Player>&) {}
	virtual void conquers(MapLoader&, Player*, vector<Player>&) {}
	virtual void redeployment(MapLoader&, Player*, vector<Player>&) {}
	virtual void score(MapLoader&, Player*, vector<Player>&) {}
	virtual void chooseDecline(Player*, vector<Player>&) {}
};

#endif
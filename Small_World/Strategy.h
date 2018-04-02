#ifndef STRATEGY_H
#define STRATEGY_H

#include "Player.h"
//#include "AI.h"
#include "MapLoader.h"
#include "Dice.h"
//#include "Aggressive.h"
//#include "Defensive.h"
//#include "Moderate.h"
//#include "Random.h"
#include <vector>
#include <string>
#include <list>

using namespace std;

class Strategy {
public:
//	Strategy() {}
	//int getPlayerType();
	virtual void execute(MapLoader&, Player*)  ;
	//virtual void pick_race(int, MapLoader&, int, vector<Player>&);
	//virtual void conquers(MapLoader&, Player* ai) ;
	//virtual void redeployment(MapLoader&, Player* ai);
	//virtual void score(MapLoader&, Player* ai);
	//virtual void chooseDecline(Player&);
};

#endif
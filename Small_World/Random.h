#pragma once
#include "Player.h"
//#include "AI.h"
#include "MapLoader.h"
#include "Dice.h"
#include <vector>
#include <string>
#include <list>
#include "Strategy.h"
using namespace std;
class Random : public Strategy {
public:
	Random() : Strategy() {}
	virtual void execute(MapLoader&, Player*);
	//virtual void pick_race(Player&);
	//virtual void conquers(MapLoader&, int, vector<AI>&);
	//virtual void redeployment(MapLoader&, int, vector<AI>&);
	//virtual void score(int, MapLoader&, vector<AI>&);
	//virtual void chooseDecline(Player&);
};
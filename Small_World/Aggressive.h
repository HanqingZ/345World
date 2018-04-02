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

class Aggressive : public Strategy {
public:
	//Aggressive();
	virtual void execute(MapLoader&, Player*);
	//virtual void pick_race(int, MapLoader&, int, vector<Player>&);
	//virtual void conquers(int, MapLoader&, int, vector<AI>&);
	//virtual void redeployment(MapLoader&, int, vector<AI>&);
	//virtual void score(int, MapLoader&, vector<AI>&);
	//virtual void chooseDecline(Player&);
};

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

class Defensive : public Strategy {
public:
	Defensive() :Strategy() {}
	virtual void execute(MapLoader&, Player*);
	//virtual void pick_race(Player&);
	//virtual void conquers(int, MapLoader&, int, vector<AI>&);
	//virtual void redeployment(int, MapLoader&, int, vector<AI>&);
	//virtual void score(int, MapLoader&, vector<AI>&);
	//virtual void chooseDecline(Player&);
};
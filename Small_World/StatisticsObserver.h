#pragma once
//#include "Decorator.h"
#include "Player.h"
#include "MapLoader.h"
using namespace std;

//class Player;

class StatisticsObserver : public Observer
{
public:
	StatisticsObserver();
//	virtual void Update(MapLoader* m);
	//virtual void Update(int playerId);
	virtual void Update(int numRegion, Player * p);
	//virtual void Update(Player*);
};


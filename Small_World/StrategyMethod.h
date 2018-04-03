#ifndef STRATEGYMETHODE_H
#define STRATEGYMETHODE_H

#include "Player.h"
#include "MapLoader.h"
#include "Dice.h"
#include "Strategy.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Aggressive : public Strategy {
public:
	Aggressive(){ cout << "You choose Aggressive for this turn.\n"; }
	virtual void execute(MapLoader&, Player*);
	virtual void pick_race(MapLoader&, vector<Player>&) {}
	virtual void conquers(MapLoader&, Player*);
	virtual void redeployment(MapLoader&, Player*) {}
	virtual void score(MapLoader&, Player*) {}
	virtual void chooseDecline(Player&) {}
};

class Defensive : public Strategy {
public:
	Defensive() :Strategy() { cout << "You choose Defensive for this turn.\n"; }
	virtual void execute(MapLoader&, Player*);
	virtual void pick_race(MapLoader&, Player*) {}
	virtual void conquers(MapLoader&, Player*) {}
	virtual void redeployment(MapLoader&, Player*) {}
	virtual void score(MapLoader&, Player*) {}
	virtual void chooseDecline(Player&) {}
};

class Moderate : public Strategy {
public:
	Moderate() : Strategy() { cout << "You choose Moderate for this turn.\n"; }
	virtual void execute(MapLoader&, Player*);
	virtual void pick_race(MapLoader&, Player*) {}
	virtual void conquers(MapLoader&, Player*) {}
	virtual void redeployment(MapLoader&, Player*) {}
	virtual void score(MapLoader&, Player*) {}
	virtual void chooseDecline(Player&) {}
};

class Random : public Strategy {
public:
	Random() : Strategy() { cout << "You choose Random for this turn.\n"; }
	virtual void execute(MapLoader&, Player*);
	virtual void pick_race(MapLoader&, Player*) {}
	virtual void conquers(MapLoader&, Player*) {}
	virtual void redeployment(MapLoader&, Player*) {}
	virtual void score(MapLoader&, Player*) {}
	virtual void chooseDecline(Player&) {}
};

#endif

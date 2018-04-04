#ifndef STRATEGYMETHODE_H
#define STRATEGYMETHODE_H

#include "Player.h"
#include "AI.h"
#include "MapLoader.h"
#include "Dice.h"
#include "Strategy.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Aggressive : public Strategy {
public:
	Aggressive(){ cout << "You are Aggressive.\n"; }
	virtual void execute(MapLoader&, Player*, vector<Player>&, int);
	//virtual void abandon(MapLoader&, Player*){}
	virtual void conquers(MapLoader&, Player*, vector<Player>&);
	//virtual void redeployment(MapLoader&, vector<Player>&){}
	virtual void score(MapLoader&, Player*, vector<Player>&);
};

class Defensive : public Strategy {
public:
	Defensive() :Strategy() { cout << "You are Defensive.\n"; }
	virtual void execute(MapLoader&, Player*, vector<Player>&, int);
	virtual void abandon(MapLoader&, Player*, vector<Player>&);
	virtual void conquers(MapLoader&, Player*, vector<Player>&);
	virtual void redeployment(MapLoader&, Player*, vector<Player>&);
	virtual void score(MapLoader&, Player*, vector<Player>&);
};

class Moderate : public Strategy {
public:
	Moderate() : Strategy() { cout << "You are Moderate.\n"; }
	virtual void execute(MapLoader&, Player*, vector<Player>&, int);
	virtual void abandon(MapLoader&, Player*, vector<Player>&);
	virtual void conquers(MapLoader&, Player*, vector<Player>&);
	virtual void redeployment(MapLoader&, Player*, vector<Player>&);
	virtual void score(MapLoader&, Player*, vector<Player>&);
	virtual void chooseDecline(MapLoader&, Player*, vector<Player>&);
};

class Random : public Strategy {
public:
	Random() : Strategy() {	cout << "You are Random.\n"; }
	virtual void execute(MapLoader&, Player*, vector<Player>&, int);
	virtual void abandon(MapLoader&, Player*, vector<Player>&);
	virtual void conquers(MapLoader&, Player*, vector<Player>&);
	virtual void redeployment(MapLoader&, Player*, vector<Player>&);
	virtual void score(MapLoader&, Player*, vector<Player>&);
	virtual void chooseDecline(MapLoader&, Player*, vector<Player>&);
private:
	int numOfDecline = 0;
};

#endif

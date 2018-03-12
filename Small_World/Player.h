#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "Races.h"
#include "PowerBudges.h"
#include "MapLoader.h"

#include <vector>
#include <string>

using namespace std;

class Player {

protected:
	int numOfPlayer;
	int id;
	Races raceOwned;
	PowerBudges powerOwned;
	int numOfTokenOwn;
	int coinOwn;
	int pickRegion;
	int tokenPlaced;

public:

	Player();
	Player(int);
	~Player();

	void pick_race(Races, PowerBudges);
	void conquers();
	void score(int);
	Races getRaces();
	PowerBudges getPower();

};

#endif

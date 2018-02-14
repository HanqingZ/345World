#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "Races.h"
#include "PowerBudges.h"
#include "MapLoader.h"


//using namespace std;

class Player {
private:
	int numOfPlayer;
	int id;
	string playerName;
	string RaceOwned;
	int numOfRaceOwn;
	int coinOwn;
public:
	Player();
	Player(int, string);
	~Player();

	int pick_race(Races, PowerBudges);
	bool conquers(int);
	int score(int);
};

#endif

#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "Races.h"

using namespace std;

class Player :{
private:
	bool active == false;
public:
	int numOfPlayer;
	int id;
	string playerName;
	int coinOwn;

	Player();
	Player(int, string);

	void pick_race();
	void conquers();
	int score(int);
}
#endif

#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "Races.h"


//using namespace std;

class Player {
private:
	int numOfPlayer;
	int id;
	string playerName;
	int coinOwn;
public:
	Player();
	Player(int, string);
	~Player();

	void pick_race();
	void conquers();
	int score(int);
};

#endif

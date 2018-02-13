#ifndef GAMEDRIVE_H
#define GAMEDRIVE_H

#include "Player.h"
#include "MapLoader.h"

#include <array>
#include <string>
using namespace std;

class GameDrive {
private:
	int numOfPlayer;
	//number of turn is from 0 to 9
	int numOfTurn;
	int numOfCombo;
	string combo[6];
/*	static const string race_type[14] = {
		"AMAZON", "DWARVE", "ELVE", "GHOUL", "GIANT", "HALFLING",
		"HUMAN", "ORCS", "RATMAN", "SKELETON", "SORCERER", "TRITON",
		"TROLL", "WIZARD" };
*/
public:
	GameDrive();
	//load map and number of player
	//GameDrive(map, int);
	~GameDrive();
	void start();

	void charaCombo();
	void setPersonalCombo(int);
};

#endif

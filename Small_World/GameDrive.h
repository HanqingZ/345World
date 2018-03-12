#ifndef GAMEDRIVE_H
#define GAMEDRIVE_H

#include "Player.h"
#include "MapLoader.h"
#include "Map.h"

#include <array>
#include <string>
using namespace std;

class GameDrive {
protected:
	Player** player;
	int numOfPlayer;
	//number of turn is from 0 to 9
	int numOfTurn;
	int numOfCombo;
	bool playerNumCheck;
	Races r;
	PowerBudges pb;
	Map testmap;
	MapLoader testMap;

public:
	GameDrive();
	~GameDrive();
	void setUp();
	void start();

	void chooseMap(int);
	void charaCombo();
//	void setPersonalCombo(int);
	string shufflePickRace(int);
	string shufflePickPower(int);
	void setRaceType(Races);
	void setPowerType(PowerBudges);
};

#endif

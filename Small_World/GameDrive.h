#ifndef GAMEDRIVE_H
#define GAMEDRIVE_H

#include "Player.h"
#include "MapLoader.h"
//#include "Map.h"

#include <array>
#include <string>
using namespace std;

class GameDrive {
private:
	Player ply;
	int numOfPlayer;
	int numOfTurn; //number of turn is from 0 to 10
	int numOfCombo;
	bool playerNumCheck;
	Races r;
	PowerBudges pb;
	MapLoader testMap;

public:
	GameDrive();
	~GameDrive();

	//Main methods
	void start();

	//Adjective methods
	void chooseMapType(int);
	void charaCombo();
	string shufflePickRace(int);
	string shufflePickPower(int);
	void setRaceType(Races);
	void setPowerType(PowerBudges);

};

#endif

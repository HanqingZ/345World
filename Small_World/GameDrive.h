#ifndef GAMEDRIVE_H
#define GAMEDRIVE_H

#include "Player.h"
#include "AI.h"
#include "MapLoader.h"
#include "Strategy.h"
#include "StrategyMethod.h"
#include "PhaseObserver.h"
#include "ObserverDecorator.h"
#include "VictoryCoinObserverDecorator.h"
#include "TokenObserverDecorator.h"
#include "StatisticsObserver.h"
#include <vector>
#include <array>
#include <string>

using namespace std;

class GameDrive {
private:
	Player ply;
	AI plyAI;
	int numOfPlayer;
	int numOfmap;
	int numOfTurn; //number of turn is from 0 to 10
	int numOfCombo;
	bool playerNumCheck;
	Races r;
	PowerBudges pb;
	MapLoader testMap;
	PhaseObserver *po;
	StatisticsObserver *so;
	Observer *victoryCoinObserver;
	Observer *tokenObserverDecorator;
	int tokenOanwser;
	int victoryCoinOAnwser;
	Strategy* strat;
public:
	GameDrive();
	~GameDrive();

	//Main methods
	void start();

	//Adjective methods
	void chooseMapType(int);
	//void pickUp(Player&);
	void charaCombo();
	string shufflePickRace(int);
	string shufflePickPower(int);
	void setRaceType(Races);
	void setPowerType(PowerBudges);
	void addObserver(vector<Player> players);
	void addVictoryCoinObserver(int victoryCoinOAnwser, vector<Player> players);
	void addTokenObserverDecorator(int tokenOanwser, vector<Player> players);
	vector<Player> players;
	//vector<AI> ai;
	void deleteObservers();
};

#endif

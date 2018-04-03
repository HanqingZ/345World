#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "Races.h"
#include "PowerBudges.h"
#include "MapLoader.h"

#include <vector>
#include <string>
#include <list>

using namespace std;

class Player {

protected:
	int numOfPlayer;	//total number of players
	int id;
	bool isComputer;
	string raceOwned;
	string powerOwned;
	int numOfTokenOwn;	//total token owned
	int coinOwn;
	int numOfDecline = 0;

	int regionId;
	Dice d;
	int diceResult;
	Races races;
	PowerBudges powerbudges;
	//Strategy* strat = nullptr;

public:
	
	Player();
	Player(int);
	~Player();

//	virtual void setStrategy(MapLoader&, int, vector<Player>&);

	void pick_race(Races&, PowerBudges&, vector<Player>&);
	void conquers(MapLoader&, int, vector<Player>&);
	void redployment(MapLoader&, vector<Player>&);
	void score(MapLoader&, vector<Player>&);
	bool chooseDecline(MapLoader&, int, vector<Player>&);

	void addCoins(int);
	void minusCoins(int);
	void addNumOfToken(int);
	void minusNumOfToken(int);
	void resetNumOfToken();
	void addRace(Races);
	void addPower(PowerBudges);
	void addJoinRegion(int);
	int getCoins();
	int getTokenNumber();
	int getPlayerId();
	bool getIsComputer();
	//vector<Region> getOwnedRegion(int);
	void shown();

	list<int> ownedRegionSet;
	//vector<Region*> ownedRegion;
	vector<Races> race;
	vector<PowerBudges> powerbudge;
	
};

#endif

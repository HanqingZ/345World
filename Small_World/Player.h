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
	string raceOwned;
	string powerOwned;
	int numOfTokenOwn;	//total token owned
	int coinOwn;
	
	int regionId;
	Dice d;
	int diceResult;
	Races races;
	PowerBudges powerbudges;
	//MapLoader mpl;

public:
	
	Player();
	Player(int);
	~Player();

	void pick_race(Races&, PowerBudges&);
	void conquers(MapLoader&, int);
	void redployment(MapLoader&);
	void score(MapLoader&);
	void chooseDecline(MapLoader&);

	void minusCoins(int);
	void addCoins(int);
	void setNumOfToken(int);
	int getCoins();
	int getTokenNumber();
	int getPlayerId();
	//void setRegionSet(int);

	list<int> ownedRegionSet;
	vector<Races> race;
	vector<PowerBudges> powerbudge;
	vector<Player> players;
	
};

#endif

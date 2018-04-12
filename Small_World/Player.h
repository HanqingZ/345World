#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"
#include "Races.h"
#include "PowerBudges.h"
#include "MapLoader.h"
#include "Subject.h"
#include <vector>
#include <string>
#include <list>

using namespace std;

class Player : public Subject {

protected:
	int numOfPlayer;	//total number of players
	int id;
	bool isComputer;
	string raceOwned;
	string powerOwned;
	int numOfTokenOwn;	//total token owned
	int coinOwn;
	string strategyType;
	int numOfDecline = 0;
	
	int regionId;
	Dice d;
	int diceResult;
	Races races;
	PowerBudges powerbudges;
	int playerTurn;
	string step;
	int regionTotalNum;
	list<int>::iterator i;
	int playerRegionSize=0;

	//Strategy* strat;

public:
	Player();
	Player(int);
	~Player();

	void pick_race(Races&, PowerBudges&, vector<Player>&);
	void conquers(MapLoader& m, int a , vector<Player>& p, int);
	void redployment(MapLoader&, vector<Player>&);
	void score(MapLoader&, vector<Player>&,int);
	bool chooseDecline(MapLoader&, int, vector<Player>&);
	void setRegionTotalNum(int regionTotalNum) {
		this->regionTotalNum = regionTotalNum;
	}
	void addCoins(int);
	void minusCoins(int);
	void setCoins(int);
	void addNumOfToken(int);
	void minusNumOfToken(int);
	void resetNumOfToken();
	void setStep(string s) { this->step = s; }
	void setPlayerTurn(int turn) { this->playerTurn = turn; }
	void setNumberOfDecline(int d) { this->numOfDecline = d; }
	void addRace(Races rs) { this->race.push_back(rs); }
	void addPower(PowerBudges pb) { this->powerbudge.push_back(pb); }
	void addJoinRegion(int rg, vector<Player>& players , int playerID);
	int getCoins();
	int getTokenNumber();
	int getPlayerId();
	int getNumberOfDecline() { return numOfDecline; }
	int getPlayerTurn() { return playerTurn; }
	string getStep() { return step;}
	bool getIsComputer();
	vector<Races> getRaceVector() {
		return this->race;
	}
	void minusRegion(int rg, vector<Player>& players, int playerID);
	string getStrategyName();
	void shown();
	int getPlayerRegionSize();
	void setPlayerRegionSize(int playerRegionSize);
	void notifys(Player*);

	list<int> ownedRegionSet;
	vector<Races> race;
	vector<PowerBudges> powerbudge;

};

#endif

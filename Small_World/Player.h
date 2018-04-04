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
	int numOfDecline = 0;
	
	int regionId;
	Dice d;
	int diceResult;
	Races races;
	PowerBudges powerbudges;
	//Strategy* strat = nullptr;
	int playerTurn;
	string step;
	int regionTotalNum;
	list<int>::iterator i;
	int playerRegionSize=0;
public:
	
	Player();
	Player(int);
	~Player();

//	virtual void setStrategy(MapLoader&, int, vector<Player>&);

	void pick_race(Races&, PowerBudges&, vector<Player>&);
	void conquers(MapLoader& m, int a , vector<Player>& p, int answer);
	void redployment(MapLoader&, vector<Player>&);
	void score(MapLoader&, vector<Player>&,int);
	bool chooseDecline(MapLoader&, int, vector<Player>&);
	void setRegionTotalNum(int regionTotalNum) {
		this->regionTotalNum = regionTotalNum;
	}
	void addCoins(int);
	void minusCoins(int);
	void addNumOfToken(int);
	void minusNumOfToken(int);
	void resetNumOfToken();
	void setStep(string s) { this->step = s; }
	void setPlayerTurn(int turn) { this->playerTurn = turn; }
	void addRace(Races);
	void addPower(PowerBudges);
	void addJoinRegion(int rg, vector<Player>& players , int playerID);
	int getCoins();
	int getTokenNumber();
	int getPlayerId();
	int getPlayerTurn() { return playerTurn; }
	string getStep() { return step;}
	bool getIsComputer();
	vector<Races> getRaceVector() {
		return this->race;
	}
	void minusRegion(int rg, vector<Player>& players, int playerID);
	void shown();
	int getPlayerRegionSize();
	void setPlayerRegionSize(int playerRegionSize);
	list<int> ownedRegionSet;
	//vector<Region*> ownedRegion;
	vector<Races> race;
	vector<PowerBudges> powerbudge;
	//list<int> GetList();

};

#endif

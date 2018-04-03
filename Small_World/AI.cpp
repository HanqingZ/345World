#include "AI.h"
#include "Strategy.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

AI::AI() {
	isComputer = true;
	this->id = 10;
	/*this->coinOwn = 5;
	this->numOfTokenOwn = 0;
	this->race.clear();
	this->powerbudge.clear();
	this->ownedRegionSet.clear();*/
	this->strat;
}

AI::AI(int id) {
	isComputer = true;
	this->id = id;
	/*this->coinOwn = 5;
	this->numOfTokenOwn = 0;
	this->race.clear();
	this->powerbudge.clear();
	this->ownedRegionSet.clear();*/

	srand((unsigned)time(0));
	int q = rand() % 4;

	switch (q)
	{
	case 0:
		strat = new Aggressive();
		strategyType = "Aggressive";
		break;
	case 1:
		strat = new Defensive();
		strategyType = "Defensive";
		break;
	case 2:
		strat = new Moderate();
		strategyType = "Moderate";
		break;
	case 3:
		strat = new Random();
		strategyType = "Random";
		break;
	}
}

AI::AI(int id, string sType) {
	isComputer = true;
	this->id = id;

	int result;

	if (sType == "Aggressive") {
		strat = new Aggressive();
		strategyType = "Aggressive";
	}
	else if (sType == "Defensive") {
		strat = new Defensive();
		strategyType = "Defensive";
	}
	else if (sType == "Moderate") {
		strat = new Moderate();
		strategyType = "Moderate";
	}
	else{
		strat = new Random();
		strategyType = "Random";
	}
}

/*
void AI::setStrategy(MapLoader &mploader, AI &pl) {
	AI* ai = &pl;
	// &(Player)
	strat->execute(mploader, ai);

	
	int q;

	cout << "Please choose a play mode for this turn.\n"
		<< "0: Aggressive\n"
		<< "1: Defensive\n"
		<< "2: Moderate\n"
		<< "3: Random\n";

	while (true) {
		cin >> q;
		if (q >= 0 && q <= 3) {
			break;
		}
		cout << "Please choose a number between 0 to 3";
	}

	switch (q)
	{
	case 0:
		strat = new Aggressive();
		strat->execute(id, mploader, numberOfTurn, ai);
		break;
	case 1:
		strat = new Defensive();
		strat->execute(id, mploader, numberOfTurn, ai);
		break;
	case 2:
		strat = new Moderate();
		strat->execute(id, mploader, numberOfTurn, ai);
		break;
	case 3:
		strat = new Random();
		strat->execute(id, mploader, numberOfTurn, ai);
		break;
	}
	
}
*/
#include <iostream>
#include "Races.h"

using namespace std;


Races::Races() {
	this->numOfToken = 0;
	this->numOfVictoryCoin = 0;
	this->active = false;
	this->raceName = "null";
	this->raceDescription = "null";
}

//Races::Races(int tk, int vc, string race) {
//	this->numOfToken = tk;
//	this->numOfVictoryCoin = vc;
//	this->raceName = race;
//}


string Races::getRaceName() {
	return raceName;
}
void Races::setRaceName(string rn) {
	this->raceName = rn;
}

int Races::getVictoryCoin() {
	return numOfVictoryCoin;
}

void Races::setVictoryCoins(int vc) {
	this->numOfVictoryCoin = vc;
}

int Races::getTokenNumber() {
	return numOfToken;
}

void Races::setTokenNumber(int tn) {
	this->numOfToken = tn;
}

bool Races::getActiveCondition() { 
	return active;
}

void Races::setActiveCondition(bool ac) {
	this->active = ac;
}

string Races::getRaceDescription() {
//	cout << raceDescription << endl;
	return raceDescription;
}

void Races::setRaceDescription(string rd) {
	this->raceDescription = rd;
}


//===================================================================

Amazon::Amazon() {
	setRaceName("Amazon");
//	setVictoryCoins(0);
	setTokenNumber(6);
	setActiveCondition(true);
	setRaceDescription("Four of your Amazon tokens may only beused for conquest, not for defense, as indicated by the +4 on the banner itself. So you start your initial turn with 10 Amazon tokens (plus any additional ones that may be granted to you by the Special Power associated with the Amazons, depending on your combo). At the end of each of your Troop Redeployments (see Troop Redeployment, p. 5), remove four tokens from the map, making sure to leave at least one Amazon token in each of your Regions if possible, and only take these four tokens back in hand to redeploy on the map once you Ready your Troops (see Ready your Troops, p. 6) at the start of your next turn.");
}

Dwarve::Dwarve() {
	setRaceName("Amazon");
//	setVictoryCoins(0);
	setTokenNumber(3);
	setActiveCondition(true);
	setRaceDescription("Each Mine Region your Dwarves occupy is worth 1 bonus Victory coin, at the end of your turn. This power is kept even when the Dwarves are In Decline.");
}

Elve::Elve() {
	setRaceName("Elve");
//	setVictoryCoins(0);
	setTokenNumber(6);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Ghoul::Ghoul() {
	setRaceName("Ghoul");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Giant::Giant() {
	setRaceName("Giant");
	//	setVictoryCoins(0);
	setTokenNumber(6);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Halfling::Halfling() {
	setRaceName("Halfling");
	//	setVictoryCoins(0);
	setTokenNumber(6);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Human::Human() {
	setRaceName("Human");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Orcs::Orcs() {
	setRaceName("Orcs");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Ratman::Ratman() {
	setRaceName("Ratman");
	//	setVictoryCoins(0);
	setTokenNumber(8);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Skeleton::Skeleton() {
	setRaceName("Skeleton");
	//	setVictoryCoins(0);
	setTokenNumber(6);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Sorcerer::Sorcerer() {
	setRaceName("Sorcerer");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Triton::Triton() {
	setRaceName("Triton");
	//	setVictoryCoins(0);
	setTokenNumber(6);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Troll::Troll() {
	setRaceName("Skeleton");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setActiveCondition(true);
	setRaceDescription(" ");
}

Wizard::Wizard() {
	setRaceName("Wizard");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setActiveCondition(true);
	setRaceDescription(" ");
}
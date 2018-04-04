#include "PowerBudges.h"

#include <iostream>

using namespace std;

PowerBudges::PowerBudges() {
	this->powerId = NULL;
	this->powerName = "";
	this->numOfToken = 0;
	this->numOfVictoryCoin = 0;
	this->active = false;
	this->immune = 0;

}

PowerBudges::~PowerBudges() {

}

int PowerBudges::getPowerId() {
	return powerId;
}

void PowerBudges::setPowerId(int pid) {
	this->powerId = pid;
}

string PowerBudges::getPowerName() {
	return powerName;
}
void PowerBudges::setPowerName(string pn) {
	this->powerName = pn;
}

int PowerBudges::getVictoryCoin() {
	return numOfVictoryCoin;
}

int PowerBudges::setVictoryCoins(int vc) {
	return numOfVictoryCoin = vc;
}

int PowerBudges::getTokenNumber() {
	return numOfToken;
}

void PowerBudges::setTokenNumber(int tn) {
	this->numOfToken = tn;
}

int PowerBudges::getImmuneNumber() {
	return immune;
}

bool PowerBudges::getActiveCondition() {
	return active;
}

void PowerBudges::setActiveCondition(bool ac) {
	this->active = ac;
}

/*
void PowerBudges::setImmune(int numOfImmune, Region *rg) {
	int i = 0;
	while (i < numOfImmune) {
		
		i++;
	}
}
*/

bool PowerBudges::checkImmuneSituation(int numOfImmune) {
	if (numOfImmune == 1 || numOfImmune == 2) {
		
		return true;
	}	
	else if (numOfImmune >= 100) {

		return true;
	}
	return false;
}


//===================================================================


Alchemist::Alchemist() {
	this->powerId = 0;
	this->powerName = "Amazon";
	this->numOfToken = 4;
	this->active = true;
}

int Alchemist::setVictoryCoins(int cn) {
	return cn += 2;
}

Berserk::Berserk() {
	this->powerId = 1;
	this->powerName = "Berserk";
	this->numOfToken = 4;
	this->active = true;
}

Bivouacking::Bivouacking() {
	this->powerId = 2;
	this->powerName = "Bivouacking";
	this->numOfToken = 5;
	this->active = true;
}

Commando::Commando() {
	this->powerId = 3;
	this->powerName = "Commando";
	this->numOfToken = 4;
	this->active = true;
}

Diplomat::Diplomat() {
	this->powerId = 4;
	this->powerName = "Diplomat";
	this->numOfToken = 5;
	this->active = true;
	this->immune = 100;
}

DragonMaster::DragonMaster() {
	this->powerId = 5;
	this->powerName = "DragonMaster";
	this->numOfToken = 5;
	this->active = true;
	this->immune = 1;
}

Flying::Flying() {
	this->powerId = 6;
	this->powerName = "Flying";
	this->numOfToken = 5;
	this->active = true;
}

Forest::Forest() {
	this->powerId = 7;
	this->powerName = "Forest";
	this->numOfToken = 5;
	this->active = true;
}
int Forest::setVictoryCoins(int cn) {
	return numOfVictoryCoin += cn;
}

Fortified::Fortified() {
	this->powerId = 8;
	this->powerName = "Fortified";
	this->numOfToken = 3;
	this->active = true;
}
int Fortified::setVictoryCoins(int cn) {
	return numOfVictoryCoin += cn;
}

Heroic::Heroic() {
	this->powerId = 9;
	this->powerName = "Heroic";
	this->numOfToken = 5;
	this->active = true;
	this->immune = 2;
}

Hill::Hill() {
	this->powerId = 10;
	this->powerName = "Hill";
	this->numOfToken = 4;
	this->active = true;
}
int Hill::setVictoryCoins(int cn) {
	return numOfVictoryCoin += cn;
}

Merchant::Merchant() {
	this->powerId = 11;
	this->powerName = "Merchant";
	this->numOfToken = 2;
	this->active = true;
}
int Merchant::setVictoryCoins(int cn) {
	return numOfVictoryCoin += cn;
}

Mounted::Mounted() {
	this->powerId = 12;
	this->powerName = "Mounted";
	this->numOfToken = 5;
	this->active = true;
}

Pillaging::Pillaging() {
	this->powerId = 13;
	this->powerName = "Pillaging";
	this->numOfToken = 5;
	this->active = true;
}
int Pillaging::setVictoryCoins(int cn) {
	return numOfVictoryCoin += cn;
}

Seafaring::Seafaring() {
	this->powerId = 14;
	this->powerName = "Seafaring";
	this->numOfToken = 5;
	this->active = true;
}

Spirit::Spirit() {
	this->powerId = 15;
	this->powerName = "Spirit";
	this->numOfToken = 5;
	this->active = true;
}

Stout::Stout() {
	this->powerId = 16;
	this->powerName = "Stout";
	this->numOfToken = 4;
	this->active = true;
}

Swamp::Swamp() {
	this->powerId = 17;
	this->powerName = "Swamp";
	this->numOfToken = 4;
	this->active = true;
}
int Swamp::setVictoryCoins(int cn) {
	return numOfVictoryCoin += cn;
}

Underworld::Underworld() {
	this->powerId = 18;
	this->powerName = "Underworld";
	this->numOfToken = 5;
	this->active = true;
}

Wealthy::Wealthy() {
	this->powerId = 19;
	this->powerName = "Wealthy";
	this->numOfToken = 4;
	this->active = true;
}
int Wealthy::setVictoryCoins(int cn) {
	return cn += 7;
}



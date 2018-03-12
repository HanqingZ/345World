#include "PowerBudges.h"

#include <iostream>

using namespace std;

PowerBudges::PowerBudges() {

	this->powerName = "";
	this->numOfToken = 0;
	this->numOfVictoryCoin = 0;
	this->powerDescription = "";

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

void PowerBudges::setVictoryCoins(int vc) {
	this->numOfVictoryCoin = vc;
}

int PowerBudges::getTokenNumber() {
	return numOfToken;
}

void PowerBudges::setTokenNumber(int tn) {
	this->numOfToken = tn;
}

string PowerBudges::getPowerDescription() {
	//	cout << raceDescription << endl;
	return powerDescription;
}

void PowerBudges::setPowerDescription(string pd) {
	this->powerDescription = pd;
}


//===================================================================


Alchemist::Alchemist() {
	setPowerName("Amazon");
//	setVictoryCoins(0);
	setTokenNumber(4);
	setPowerDescription("");
}

Berserk::Berserk() {
	setPowerName("Berserk");
//	setVictoryCoins(0);
	setTokenNumber(4);
	setPowerDescription("");
}

Bivouacking::Bivouacking() {
	setPowerName("Bivouacking");
//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Commando::Commando() {
	setPowerName("Commando");
//	setVictoryCoins(0);
	setTokenNumber(4);
	setPowerDescription("");
}

Diplomat::Diplomat() {
	setPowerName("Diplomat");
//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

DragonMaster::DragonMaster() {
	setPowerName("DragonMaster");
//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Flying::Flying() {
	setPowerName("Flying");
//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Forest::Forest() {
	setPowerName("Forest");
//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Fortified::Fortified() {
	setPowerName("Fortified");
//	setVictoryCoins(0);
	setTokenNumber(3);
	setPowerDescription("");
}

Heroic::Heroic() {
	setPowerName("Heroic");
//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Hill::Hill() {
	setPowerName("Hill");
//	setVictoryCoins(0);
	setTokenNumber(4);
	setPowerDescription("");
}

Merchant::Merchant() {
	setPowerName("Merchant");
//	setVictoryCoins(0);
	setTokenNumber(2);
	setPowerDescription("");
}

Mounted::Mounted() {
	setPowerName("Mounted");
//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Pillaging::Pillaging() {
	setPowerName("Pillaging");
//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Seafaring::Seafaring() {
	setPowerName("Seafaring");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Spirit::Spirit() {
	setPowerName("Spirit");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Stout::Stout() {
	setPowerName("Stout");
	//	setVictoryCoins(0);
	setTokenNumber(4);
	setPowerDescription("");
}

Swamp::Swamp() {
	setPowerName("Swamp");
	//	setVictoryCoins(0);
	setTokenNumber(4);
	setPowerDescription("");
}

Underworld::Underworld() {
	setPowerName("Underworld");
	//	setVictoryCoins(0);
	setTokenNumber(5);
	setPowerDescription("");
}

Wealthy::Wealthy() {
	setPowerName("Wealthy");
	//	setVictoryCoins(0);
	setTokenNumber(4);
	setPowerDescription("");
}

/*
void Alchemist::setPowerName() {
	this->powerName = "Alchemist";
}

void Alchemist::setPowerDescription() {
	this->powerDescription = "Collect 2 bonus Victory coins at the end of each turn your race hasn't yet gone into Decline.";
}

void Alchemist::setTokenNumber() {
	this->numOfToken = 0;
}

void Alchemist::setVictoryCoin() {
	this->numOfVictoryCoin = 2;
}

void Alchemist::show() {
	string pn = getPowerName();
	string pd = getPowerDescription();
	cout << pn << ": " << pd << endl;
}
*/

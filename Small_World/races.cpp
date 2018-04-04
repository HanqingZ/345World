#include <iostream>
#include "Races.h"

using namespace std;


Races::Races() {
	this->raceId = 0;
	this->numOfToken = 0;
	this->numOfVictoryCoin = 0;
	this->active = false;
	this->raceName = "";
}

//Races::Races(int tk, int vc, string race) {
//	this->numOfToken = tk;
//	this->numOfVictoryCoin = vc;
//	this->raceName = race;
//}

Races::~Races() {

}

int Races::getRaceId() {
	return raceId;
}

void Races::setRaceId(int rid) {
	this->raceId = rid;
}

string Races::getRaceName() {
	return raceName;
}
void Races::setRaceName(string rn) {
	this->raceName = rn;
}

int Races::getVictoryCoin() {
	return numOfVictoryCoin;
}

int Races::setVictoryCoins(int vc) {
	return this->numOfVictoryCoin = vc;
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


//===================================================================

Amazon::Amazon() {
	this->raceId = 0;
	this->numOfToken = 6;
	this->active = true;
	this->raceName = "Amazon";
}

Dwarve::Dwarve() {
	this->raceId = 1;
	this->numOfToken = 3;
	this->active = true;
	this->raceName = "Dwarve";
}
int Dwarve::setVictoryCoins(int cn) {
	return cn += 1;
}

Elve::Elve() {
	this->raceId = 2;
	this->raceName = "Elve";
	this->numOfToken = 6;
	this->active = true;
}

Ghoul::Ghoul() {
	this->raceId = 3;
	this->raceName = "Ghoul";
	this->numOfToken = 5;
	this->active = true;
}

Giant::Giant() {
	this->raceId = 4;
	this->raceName = "Giant";
	this->numOfToken = 6;
	this->active = true;
}

Halfling::Halfling() {
	this->raceId = 5;
	this->raceName = "Halfling";
	this->numOfToken = 6;
	this->active = true;
}

Human::Human() {
	this->raceId = 6;
	this->raceName = "Human";
	this->numOfToken = 5;
	this->active = true;
}
int Human::setVictoryCoins(int cn) {
	return cn += 1;
}

Orcs::Orcs() {
	this->raceId = 7;
	this->raceName = "Orcs";
	this->numOfToken = 5;
	this->active = true;
}
int Orcs::setVictoryCoins(int cn) {
	return cn += 1;
}

Ratman::Ratman() {
	this->raceId = 8;
	this->raceName = "Ratman";
	this->numOfToken = 8;
	this->active = true;
}

Skeleton::Skeleton() {
	this->raceId = 9;
	this->raceName = "Skeleton";
	this->numOfToken = 6;
	this->active = true;
}

Sorcerer::Sorcerer() {
	this->raceId = 10;
	this->raceName = "Sorcerer";
	this->numOfToken = 5;
	this->active = true;
}

Triton::Triton() {
	this->raceId = 11;
	this->raceName = "Triton";
	this->numOfToken = 6;
	this->active = true;
}

Troll::Troll() {
	this->raceId = 12;
	this->raceName = "Skeleton";
	this->numOfToken = 5;
	this->active = true;
}

Wizard::Wizard() {
	this->raceId = 13;
	this->raceName = "Wizard";
	this->numOfToken = 5;
	this->active = true;
}
int Wizard::setVictoryCoins(int cn) {
	return cn += 1;
}
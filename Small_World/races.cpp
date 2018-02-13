#include <iostream>
#include <string>
#include "Races.h"

using namespace std;

/*enum RaceType {
	amazon, dwarve, elve, ghoul, giant, halfling, 
	human, orcs, ratman, skeleton, sorcerer, triton,
	troll, wizard
};
*/

Races::Races() {
	string raceType[14] = {
		"AMAZON", "DWARVE", "ELVE", "GHOUL", "GIANT", "HALFLING",
		"HUMAN", "ORCS", "RATMAN", "SKELETON", "SORCERER", "TRITON",
		"TROLL", "WIZARD" };
	int raceNumber = 0;
	string raceBanner;
	string races;
}


void Races::findRaceAbility(int num) {

	switch (num)
	{
	case 0: Races::Amazon(); break;
	case 1: Races::Dwarve(); break;
	case 2: Races::Elve(); break;
	case 3: Races::Ghoul(); break;
	case 4: Races::Giant(); break;
	case 5: Races::Halfling(); break;
	case 6: Races::Human(); break;
	case 7: Races::Orcs(); break;
	case 8: Races::Ratman(); break;
	case 9: Races::Skeleton(); break;
	case 10: Races::Sorcerer(); break;
	case 11: Races::Triton(); break;
	case 12: Races::Troll(); break;
	case 13: Races::Wizard(); break;
	default:
		break;
	}
}

//void Races::setRaceBanner(string rb) {
//	this->raceBanner = rb;
//}

string Races::getRaceType(int raceNumber) {
	int races = raceNumber;
	return Races::raceType[races];
}

void setRaceBanner(string racebanner) {
//	this->raceBanner = racebanner;
}

void Races::Amazon() {

}

void Races::Dwarve() {

}

void Races::Elve() {

}

void Races::Ghoul() {

}

void Races::Giant() {

}

void Races::Halfling() {

}

void Races::Human() {

}

void Races::Orcs() {

}

void Races::Ratman() {

}

void Races::Skeleton() {

}

void Races::Sorcerer() {

}

void Races::Triton() {

}

void Races::Troll() {

}

void Races::Wizard() {

}
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
	/*string raceType[14] = {
		"AMAZON", "DWARVE", "ELVE", "GHOUL", "GIANT", "HALFLING",
		"HUMAN", "ORCS", "RATMAN", "SKELETON", "SORCERER", "TRITON",
		"TROLL", "WIZARD" };*/
	int raceNumber = 0;
	string raceBanner = "";
	string races;
}


void Races::useRaceAbility(int num, bool active) {

	if (num == 0 && active == true) {
		Races::Amazon();
	}
	else if (num == 1) {
		Races::Dwarve(active);
	}
	else if (num == 2 && active == true) {
		Races::Elve();
	}
	else if (num == 3 && active == true) {
		Races::Ghoul();
	}
	else if (num == 4 && active == true) {
		Races::Giant();
	}
	else if (num == 5 && active == true) {
		Races::Halfling();
	}
	else if (num == 6) {
		Races::Human(active);
	}
	else if (num == 7 && active == true) {
		Races::Orcs();
	}
	else if (num == 8 && active == true) {
		Races::Ratman();
	}
	else if (num == 9 && active == true) {
		Races::Skeleton();
	}
	else if (num == 10 && active == true) {
		Races::Sorcerer();
	}
	else if (num == 11 && active == true) {
		Races::Triton();
	}
	else if (num == 12 && active == true) {
		Races::Troll();
	}
	else if (num == 13) {
		Races::Wizard(active);
	}

/*	switch (num)
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
*/
}

//void Races::setRaceBanner(string rb) {
//	this->raceBanner = rb;
//}

string Races::getRaceType(int raceNumber) {
	int races = raceNumber;
	return Races::raceType[raceNumber];
}

void setRaceBanner(string racebanner) {
//	this->raceBanner = racebanner;
}

int Races::Amazon() {

}

int Races::Dwarve(bool a) {
	if (a == true) {

	}
	else {

	}
}

int Races::Elve() {

}

int Races::Ghoul() {

}

int Races::Giant() {

}

int Races::Halfling() {

}

int Races::Human(bool a) {
	if (a == true) {

	}
	else {

	}
}

int Races::Orcs() {

}

int Races::Ratman() {

}

int Races::Skeleton() {

}

int Races::Sorcerer() {

}

int Races::Triton() {

}

int Races::Troll() {

}

int Races::Wizard(bool a) {
	if (a == true) {

	}
	else {

	}
}
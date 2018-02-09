#include <iostream>
#include <string>
#include "Races.h"

using namespace std;

enum RaceType {
	amazon, dwarve, elve, ghoul, giant, halfling, 
	human, orcs, ratman, skeleton, sorcerer, triton,
	troll, wizard
};

Races::Races() {

}

string Races::setRace(RaceType rp) {
	RaceType race = rp;
	switch (race)
	{
	case amazon: Races::Amazon(); break;
	case dwarve: Races::Dwarve(); break;
	case elve: Races::Elve(); break;
	case ghoul: Races::Ghoul(); break;
	case giant: Races::Giant(); break;
	case halfling: Races::Halfling(); break;
	case human: Races::Human(); break;
	case orcs: Races::Orcs(); break;
	case ratman: Races::Ratman(); break;
	case skeleton: Races::Skeleton(); break;
	case sorcerer: Races::Sorcerer(); break;
	case triton: Races::Triton(); break;
	case troll: Races::Troll(); break;
	case wizard: Races::Wizard(); break;
	default:
		break;
	}
}




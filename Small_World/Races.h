#ifndef _RACES_H
#define _RACES_H

#include <iostream>
#include <string>
#include <array>

class Races {
	
private: 
	int numOfRace;
	int numOfVictoryCoin;
	string raceBanner;
	bool active = true;
	int raceNumber;

public:
	const string raceType[14] = {
		"AMAZON", "DWARVE", "ELVE", "GHOUL", "GIANT", "HALFLING",
		"HUMAN", "ORCS", "RATMAN", "SKELETON", "SORCERER", "TRITON",
		"TROLL", "WIZARD" };
		
	Races();
//	~Races();
	void useRaceAbility(int, bool);
	string getRaceType(int);
//	void setRaceType(string[]);
	void setRaceBanner(string);

	int Amazon();
	int Dwarve(bool);
	int Elve();
	int Ghoul();
	int Giant();
	int Halfling();
	int Human(bool);
	int Orcs();
	int Ratman();
	int Skeleton();
	int Sorcerer();
	int Triton();
	int Troll();
	int Wizard(bool);
};

#endif

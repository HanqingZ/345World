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
	string* raceType[14];
		/*
		= {
		"AMAZON", "DWARVE", "ELVE", "GHOUL", "GIANT", "HALFLING",
		"HUMAN", "ORCS", "RATMAN", "SKELETON", "SORCERER", "TRITON",
		"TROLL", "WIZARD" };
		*/
	Races();
//	~Races();
	void findRaceAbility(int);
	string getRaceType(int);
//	void setRaceType(string[]);
	void setRaceBanner(string);

	void Amazon();
	void Dwarve();
	void Elve();
	void Ghoul();
	void Giant();
	void Halfling();
	void Human();
	void Orcs();
	void Ratman();
	void Skeleton();
	void Sorcerer();
	void Triton();
	void Troll();
	void Wizard();
};

#endif

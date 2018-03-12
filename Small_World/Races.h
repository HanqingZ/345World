#ifndef _RACES_H
#define _RACES_H

#include <iostream>
#include <string.h>

using namespace std;

class Races {
	
protected: 
	int numOfToken;
	int numOfVictoryCoin;
	string raceName;
	bool active;
	string raceDescription;

public:		
	Races();
//	Races(int, int, string);

	string getRaceName();
	void setRaceName(string);
	int getVictoryCoin();
	void setVictoryCoins(int);
	int getTokenNumber();
	void setTokenNumber(int);
	bool getActiveCondition();
	void setActiveCondition(bool);
	string getRaceDescription();
	void setRaceDescription(string);
	
};

//===================================================================

class Amazon : public Races {
public:
	Amazon();
};

class Dwarve : public Races {
public:
	Dwarve();
};
	
class Elve : public Races{
public:
	Elve();
};

class Ghoul : public Races{
public:
	Ghoul();
};

class Giant : public Races {
public:
	Giant();
};

class Halfling : public Races {
public:
	Halfling();
};

class Human : public Races {
public:
	Human();
};

class Orcs : public Races {
public:
	Orcs();
};

class Ratman : public Races {
public:
	Ratman();
};

class Skeleton : public Races {
public:
	Skeleton();
};

class Sorcerer : public Races {
public:
	Sorcerer();
};

class Triton : public Races {
public:
	Triton();
};

class Troll : public Races {
public:
	Troll();
};

class Wizard : public Races {
public:
	Wizard();
};

#endif

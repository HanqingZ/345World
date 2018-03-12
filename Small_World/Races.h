#ifndef _RACES_H
#define _RACES_H

#include <iostream>
#include <string.h>

using namespace std;

class Races {
	
protected: 
	int raceId;
	int numOfToken;
	int numOfVictoryCoin;
	string raceName;
	bool active;

public:		
	Races();
//	Races(int, int, string);
	~Races();

	int getRaceId();
	void setRaceId(int);
	string getRaceName();
	void setRaceName(string);
	int getVictoryCoin();
	virtual void setVictoryCoins(int);
	int getTokenNumber();
	void setTokenNumber(int);
	bool getActiveCondition();
	void setActiveCondition(bool);
	int atConquer();
	int atBattle();
	
};

//===================================================================

class Amazon : public Races {
public:
	Amazon();
	//int atConquer();	//for next assignment
};

class Dwarve : public Races {
public:
	Dwarve();
	void setVictoryCoins(int);
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
	void setVictoryCoins(int);
};

class Orcs : public Races {
public:
	Orcs();
	void setVictoryCoins(int);
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
	void setVictoryCoins(int);
};

#endif

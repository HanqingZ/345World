#ifndef SPPOWER_H
#define SPPOWER_H

#include <iostream>
#include <string>
//#include "Region.h"
//#include "Player.h"

using namespace std;

class PowerBudges {

protected:
	int powerId;
	int numOfToken;
	int numOfVictoryCoin;
	string powerName;
	bool active;
	int immune;		//some races can set regions to be immune

public:
	PowerBudges();
	~PowerBudges();

	int getPowerId();
	void setPowerId(int);
	string getPowerName();
	void setPowerName(string);
	int getVictoryCoin();
	virtual int setVictoryCoins(int);
	int getTokenNumber();
	void setTokenNumber(int);
	bool getActiveCondition();
	void setActiveCondition(bool);
	int getImmuneNumber();
	//void setTokenNumber(int);
//	void setImmune(int, Region*);		//for some powers, they can be immune for some regions
	bool checkImmuneSituation(int);

};


//===================================================================

class Alchemist : public PowerBudges {
public:
	Alchemist();
	int setVictoryCoins(int);
};

class Berserk : public PowerBudges {
public:
	Berserk();
};

class Bivouacking : public PowerBudges {
public:
	Bivouacking();
};

class Commando : public PowerBudges {
public:
	Commando();
};

class Diplomat : public PowerBudges {
public:
	Diplomat();
};

class DragonMaster : public PowerBudges {
public:
	DragonMaster();
};

class Flying : public PowerBudges {
public:
	Flying();
};

class Forest : public PowerBudges {
public:
	Forest();
	int setVictoryCoins(int);
};

class Fortified : public PowerBudges {
public:
	Fortified();
	int setVictoryCoins(int);
};

class Heroic : public PowerBudges {
public:
	Heroic();
};

class Hill : public PowerBudges {
public:
	Hill();
	int setVictoryCoins(int);
};

class Merchant : public PowerBudges {
public:
	Merchant();
	int setVictoryCoins(int);
};

class Mounted : public PowerBudges {
public:
	Mounted();
};

class Pillaging : public PowerBudges {
public:
	Pillaging();
	int setVictoryCoins(int);
};

class Seafaring : public PowerBudges {
public:
	Seafaring();
};

class Spirit : public PowerBudges {
public:
	Spirit();
};

class Stout : public PowerBudges {
public:
	Stout();
};

class Swamp : public PowerBudges {
public:
	Swamp();
	int setVictoryCoins(int);
};

class Underworld : public PowerBudges {
public:
	Underworld();
};

class Wealthy : public PowerBudges {
public:
	Wealthy();
	int setVictoryCoins(int);
};

#endif
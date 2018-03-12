#ifndef SPPOWER_H
#define SPPOWER_H

#include <iostream>
#include <string>

using namespace std;

class PowerBudges {

protected:
	int numOfToken;
	int numOfVictoryCoin;
	string powerName;
	bool active;
	string powerDescription;

public:
	PowerBudges();
//	~PowerBudges();

	/*
	virtual void setPowerName();
	virtual void setPowerDescription();
	virtual void setTokenNumber();
	virtual void setVictoryCoin();

	virtual string getPowerName() { return powerName; };
	virtual string getPowerDescription() { return powerDescription; };
	virtual int getTokenNumber() { return numOfToken; };
	virtual int getVictoryCoin() { return numOfVictoryCoin; };

	virtual void show();*/

	string getPowerName();
	void setPowerName(string);
	int getVictoryCoin();
	void setVictoryCoins(int);
	int getTokenNumber();
	void setTokenNumber(int);
	bool getActiveCondition();
	void setActiveCondition(bool);
	string getPowerDescription();
	void setPowerDescription(string);

};


//===================================================================

class Alchemist : public PowerBudges {
public:
	Alchemist();
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
};

class Fortified : public PowerBudges {
public:
	Fortified();
};

class Heroic : public PowerBudges {
public:
	Heroic();
};

class Hill : public PowerBudges {
public:
	Hill();
};

class Merchant : public PowerBudges {
public:
	Merchant();
};

class Mounted : public PowerBudges {
public:
	Mounted();
};

class Pillaging : public PowerBudges {
public:
	Pillaging();
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
};

class Underworld : public PowerBudges {
public:
	Underworld();
};

class Wealthy : public PowerBudges {
public:
	Wealthy();
};

#endif
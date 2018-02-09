#include <iostream>

#ifndef SPPOWER_H
#define SPPOWER_H

class  PowerBudges {
	enum Powers;
	Powers specialPower;
	int coinsOwn;
	int regionsOwn;
public:
	PowerBudges();
	PowerBudges(Powers, int, int);
	int Alchemist(int, int);
	void Berserk();
	void Bivouacking();
	void Commando();
	void Diplomat();
	void DragonMaster();
	void Flying();
	void Forest();
	void Fortified();
	void Heroic();
	void Hill();
	void Merchant();
	void Mounted();
	void Pillaging();
	void Seafaring();
	void Spirit();
	void Stout();
	void Swamp();
	void Underworld();
	void Wealthy();
};

#endif
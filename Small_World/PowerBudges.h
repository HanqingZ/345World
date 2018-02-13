#ifndef SPPOWER_H
#define SPPOWER_H

#include <string>

class PowerBudges {
public:
	PowerBudges();
	~PowerBudges();

	enum Powers {
		alchemist, berserk, bivouacking, commando,
		diplomat, dragonMaster, flying, forest,
		fortified, heroic, hill, merchant, mounted,
		pillaging, seafaring, spirit, stout, swamp,
		underworld, wealthy
	};
	void setPowerBudges(Powers, int, int);

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
private:
	Powers specialPower;
	int coinsOwn;
	int regionsOwn;
};

#endif
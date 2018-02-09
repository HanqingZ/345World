#include "PowerBudges.h"

#include <iostream>

enum Powers {
	alchemist, berserk, bivouacking, commando, 
	diplomat, dragonMaster, flying, forest,
	fortified, heroic, hill, merchant, mounted,
	pillaging, seafaring, spirit, stout, swamp, 
	underworld, wealthy
};

PowerBudges::PowerBudges() {

}

PowerBudges::PowerBudges(Powers power, int coins, int regions) {
	this->coinsOwn = coins;
	this->regionsOwn = regions;

	Powers specialPower = power;
	switch (power) {
	case alchemist: PowerBudges::Alchemist(coinsOwn, regionsOwn); break;
	case berserk: Berserk(); break;
	case bivouacking: Bivouacking(); break;
	case commando: Commando(); break;
	case diplomat: Diplomat(); break;
	case dragonMaster: DragonMaster(); break;
	case flying: Flying(); break;
	case forest: Forest(); break;
	case fortified: Fortified(); break;
	case heroic: Heroic(); break;
	case hill: Hill(); break;
	case merchant: Merchant(); break;
	case mounted: Mounted(); break;
	case pillaging: Pillaging(); break;
	case seafaring: Seafaring(); break;
	case spirit: Spirit(); break;
	case stout: Stout(); break;
	case swamp: Swamp(); break;
	case underworld: Underworld(); break;
	case wealthy: Wealthy(); break;
	default:
		break;
	}
}



int PowerBudges::Alchemist(int coins, int regions) {
	return 
}
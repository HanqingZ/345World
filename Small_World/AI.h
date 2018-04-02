#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Strategy.h"
#include <vector>
#include <string>
#include <iostream>
#include "Aggressive.h"
#include "Defensive.h"
#include "Moderate.h"
#include "Random.h"
using namespace std;

class AI : public Player {
public:
	AI();
	AI(int);
	//~AI();
	//void setStrategy(MapLoader&, AI&);

	Strategy* strat;
	string strategyType;
};

#endif

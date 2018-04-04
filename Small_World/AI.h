#ifndef AI_H
#define AI_H

#include "Player.h"
//#include "Strategy.h"
//#include "StrategyMethod.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AI : public Player {
public:
	AI();
	AI(int);
	AI(int, string);
	//void setStrategy(MapLoader&, AI&);

	//Strategy* strat;
	string strategyType;
};

#endif

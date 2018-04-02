#include "Strategy.h"
#include "MapLoader.h"
#include "Dice.h"
#include "Player.h"
#include "AI.h"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;
void Defensive::execute(MapLoader& mploader, Player* ai) {
	cout << "You choose Aggressive for this turn.\n";
	//conquers(mploader, ai);
	//score(pid, mploader, player);
}
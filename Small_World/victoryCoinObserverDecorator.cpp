#include "VictoryCoinObserverDecorator.h"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
#include "Player.h"

using namespace std;
void VictoryCoinObserverDecorator::Update(Player* player) {

	int coin = player->getCoins();
	int playerId = player->getPlayerId();
	cout << "Player " << playerId << " has " << coin << "tokens" << endl;
}

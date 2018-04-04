#include "PhaseObserver.h"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
#include "Player.h"

using namespace std;

PhaseObserver::PhaseObserver()
{
	observerType = "phase observer";
}

void PhaseObserver::Update(Player* player)
{
	string step = player->getStep();
	int coin = player->getCoins();
	int turn = player->getPlayerTurn();
	int playerId = player->getPlayerId();

	if (step == "pick") {
		cout << "Turn->"<< turn <<" Player " << playerId << ": Please pick your race and power combo (1 to 6)." << endl;
	}
	else if (step == "conquer") {
		cout << "Turn->" << turn << " Player " << playerId << ": Please conquer some regions." << endl;
	}
	else if (step == "reDeploy") {
		cout << "Turn->" << turn << " Player " << playerId << ": Please make your redeployment." << endl;
	}
	else if (step == "score") {
		cout << "Turn->" << turn << " Player " << playerId << ": Scores some victory coins." << endl;
	}
	else if (step == "decline") {

	}
}


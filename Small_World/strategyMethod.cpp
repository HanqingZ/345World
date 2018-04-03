#include "StrategyMethod.h"
#include "Player.h"
#include "MapLoader.h"
#include "Dice.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Aggressive::execute(MapLoader& mploader, Player* player) {
	conquers(mploader, player);
}

void Aggressive::conquers(MapLoader& mploader, Player* player) {
	int rnum, localToken;
	Dice dice;
	bool answer = false;

	while (player->getTokenNumber() > 1) {
		cout << "Please choose a region you want to conquer\n";
		cin >> rnum;
		if (mploader.checkCanConquer(rnum, player->getPlayerId())) {
			localToken = mploader.regions[rnum].getContainToken();
			localToken += 2;
			if (localToken > player->getTokenNumber()) {
				int i = dice.rollingResult();
				if ((i + player->getTokenNumber()) >= localToken) {
					player->minusNumOfToken(localToken - i);
					answer = true;
				}
				else {
					break;
				}
			}
			player->minusNumOfToken(localToken);
			if (mploader.regions[rnum].getOwnerId() != 100) {
				int c = mploader.regions[rnum].getOwnerId();
				player[c].ownedRegionSet.remove(c);
				player[c].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
				mploader.regions[rnum].resetContainToken(false);
			}

			if (mploader.regions[rnum].getIsLostTribes()) {
				mploader.regions[rnum].minusContainToken(1);
				mploader.regions[rnum].setIsLostTribes(false);
			}

			player->ownedRegionSet.push_back(rnum);
			mploader.regions[rnum].setOwnerID(player->getPlayerId());

			mploader.regions[rnum].addContainToken(localToken);

			if (answer == true)
				break;
		}
	}
}


void Defensive::execute(MapLoader& mploader, Player* player) {
	cout << "You choose Defensive for this turn.\n";
	conquers(mploader, player);
	score(mploader, player);
}



void Moderate::execute(MapLoader& mploader, Player* player) {
	cout << "You choose Moderate for this turn.\n";
	conquers(mploader, player);
	score(mploader, player);
}


void Random::execute(MapLoader& mploader, Player* player) {
	cout << "You choose Random for this turn.\n";
	conquers(mploader, player);
	score(mploader, player);
}
#include "StrategyMethod.h"
#include "Player.h"
#include "MapLoader.h"
#include "Dice.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void Aggressive::execute(MapLoader& mploader, Player* player, vector<Player>& ply, int numOfTurn) {
	player->setRegionTotalNum(mploader.regions.size());
	if (!player->ownedRegionSet.empty()) {
		//Take all tokens from the owned region, only leave one token
		for (auto i : player->ownedRegionSet) {
			player->addNumOfToken(mploader.regions[i].getUsefulContainToken());
			cout << "You got " << player->getTokenNumber() << endl;
			mploader.regions[i].resetContainToken(false);
		}
	}
}

void Aggressive::pickRace(Races &rs, PowerBudges &pb, Player* player) {
	if (!player->race.empty() && !player->powerbudge.empty()) {
		for (auto r : player->race) {
			r.setActiveCondition(false);
		}
		for (auto p : player->powerbudge) {
			p.setActiveCondition(false);
		}
	}

	player->addRace(rs);
	player->addPower(pb);
	//cout << player[id-1].getRaceVector().at(0).getRaceId() << endl;

	player->addNumOfToken(rs.getTokenNumber() + pb.getTokenNumber());

	cout << "You pick the race " << rs.getRaceName()
		<< " with special power " << pb.getPowerName()
		<< " owns " << player->getTokenNumber() << " tokens on hand \n";
}

void Aggressive::conquers(MapLoader& mploader, Player* player, vector<Player>& ply, int ans) {
	int rnum;
	int localToken;  //minimum tokens needed to conquer the region
	Dice dice;
	int i = 0;
	bool answer = false;

	if (!player->ownedRegionSet.empty()) {
		//Take all tokens from the owned region, only leave one token
		for (auto i : player->ownedRegionSet) {
			player->addNumOfToken(mploader.regions[i].getUsefulContainToken());
			mploader.regions[i].resetContainToken(false);
			cout << "You owned " << player->getTokenNumber() << " tokens.\n";
		}
	}

	while (player->getTokenNumber() > 0) {
		cout << "Player " << player->getPlayerId() << ", please select a region to conquer( must be a region near a border or a region adjacent to the regions you own)" << endl;
		cin >> rnum;
		if (mploader.checkCanConquer(rnum, player->getPlayerId())) {
			localToken = mploader.regions[rnum].getContainToken() + 2;

			if (localToken > player->getTokenNumber()) {
				cout << "You don't have enough tokens. Please roll the dice.\n";
				i = dice.rollingResult();
				if ((i + player->getTokenNumber()) >= localToken) {
					if (mploader.regions[rnum].getOwnerId() != 100) {
						int c = mploader.regions[rnum].getOwnerId();
						ply[c - 1].minusRegion(rnum, ply, c);
						ply[c - 1].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
						mploader.regions[rnum].resetContainToken(false);
					}
					if (mploader.regions[rnum].getIsLostTribes()) {
						mploader.regions[rnum].minusContainToken(1);
						mploader.regions[rnum].setIsLostTribes(false);
					}
					player->addJoinRegion(rnum, ply, player->getPlayerId());
					mploader.regions[rnum].setOwnerID(player->getPlayerId());

					mploader.regions[rnum].addContainToken(player->getTokenNumber());
					player->resetNumOfToken();
					answer = true;
				}
				else {
					cout << "You can't conquer the region " << rnum << endl;
					break;
				}
			}

			else {
				if (mploader.regions[rnum].getOwnerId() != 100) {
					int c = mploader.regions[rnum].getOwnerId();
					ply[c - 1].minusRegion(rnum, ply, c);
					ply[c - 1].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
					mploader.regions[rnum].resetContainToken(false);
				}
				if (mploader.regions[rnum].getIsLostTribes()) {
					mploader.regions[rnum].minusContainToken(1);
					mploader.regions[rnum].setIsLostTribes(false);
				}

				player->addJoinRegion(rnum, ply, player->getPlayerId());
				mploader.regions[rnum].setOwnerID(player->getPlayerId());

				mploader.regions[rnum].addContainToken(localToken);
				player->minusNumOfToken(localToken);
			}

			cout << "You used " << localToken << " tokens to conquer this region" << ", and you have " << player->getTokenNumber() << " tokens left" << endl;

			if (answer == 1) {
				player->notifys(player);
			}

			if (answer == true)
				break;
		}
		else {
			cout << "Please choose a valid region number.\n";
		}
	}
}

void Aggressive::score(MapLoader& mploader, Player* player, vector<Player>& ply, int ans) {
	for (auto r : player->race) {
		for (auto s : player->ownedRegionSet) {
			if (mploader.regions[s].getRegionType() == "Farmland"
				&& (r.getRaceName() == "Human")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getIsMagic()
				&& (r.getRaceName() == "Wizard")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (r.getRaceName() == "Orcs") {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getIsLairs()
				&& (r.getRaceName() == "Dwarves")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
		}
	}
	for (auto p : player->powerbudge) {
		for (auto s : player->ownedRegionSet) {
			if (mploader.regions[s].getContainFortresses()
				&& p.getPowerName() == "Fortified") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Hill"
				&& p.getPowerName() == "Hill") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Forest"
				&& p.getPowerName() == "Forest") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Swamp"
				&& p.getPowerName() == "Swamp") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (p.getPowerName() == "Merchant") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (p.getPowerName() == "Pillaging") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
		}
		if (p.getPowerName() == "Alchemist") {
			player->setCoins(p.setVictoryCoins(player->getCoins()));
		}
		else if (p.getPowerName() == "Wealthy") {
			player->setCoins(p.setVictoryCoins(player->getCoins()));
		}
	}

	player->addCoins(player->ownedRegionSet.size());
	cout << "You owns " << player->getCoins() << " coins this turn.\n";

	if (ans == 1) {
		player->notifys(player);
	}
}

//================================================================================
//================================================================================

void Defensive::execute(MapLoader& mploader, Player* player, vector<Player>& ply, int numOfTurn) {
	player->setRegionTotalNum(mploader.regions.size());
	string ans;
	if (player->getTokenNumber() < 2) {
		cout << "Do you want to abandon your regions? (y or n)\n";
		cin >> ans;
		if (ans == "y") {
			abandon(mploader, player, ply);
		}
	}
	if (!player->ownedRegionSet.empty()) {
		//Take all tokens from the owned region, only leave one token
		for (auto i : player->ownedRegionSet) {
			player->addNumOfToken(mploader.regions[i].getUsefulContainToken());
			cout << "You got " << player->getTokenNumber() << endl;
			mploader.regions[i].resetContainToken(false);
		}
	}
}

void Defensive::pickRace(Races &rs, PowerBudges &pb, Player* player) {
	if (!player->race.empty() && !player->powerbudge.empty()) {
		for (auto r : player->race) {
			r.setActiveCondition(false);
		}
		for (auto p : player->powerbudge) {
			p.setActiveCondition(false);
		}
	}

	player->addRace(rs);
	player->addPower(pb);
	//cout << player[id-1].getRaceVector().at(0).getRaceId() << endl;

	player->addNumOfToken(rs.getTokenNumber() + pb.getTokenNumber());

	cout << "You pick the race " << rs.getRaceName()
		<< " with special power " << pb.getPowerName()
		<< " owns " << player->getTokenNumber() << " tokens on hand \n";
}

void Defensive::abandon(MapLoader& mploader, Player* player, vector<Player>& ply) {
	int rid;
	string a;

	cout << "You owns ";
	for (auto i : player->ownedRegionSet) {
		cout << i << " ";
	}
	cout << endl;
	while (true) {
		cout << "Choose a region you want to abandon?\n";
		cin >> rid;
		if (mploader.checkCanConquer(rid, player->getPlayerId())) {
			player->addNumOfToken(mploader.regions[rid].getUsefulContainToken());
			mploader.regions[rid].resetContainToken(true);
			mploader.regions[rid].setOwnerID(100);
			player->minusRegion(rid, ply, player->getPlayerId());
			cout << "Now you have " << player->getTokenNumber() << " tokens.\n";
			cout << "Do u still want to abandon regions? (y or n)";
			cin >> a;
			if (a != "y")
				break;
		}
		else {
			cout << "The region u enter is not belongs to you\n";
			cout << "Please choose a valid number" << endl;
		}
	}
}

void Defensive::conquers(MapLoader& mploader, Player* player, vector<Player>& ply, int ans) {


	int rnum;
	int localToken;  //minimum tokens needed to conquer the region
	Dice dice;
	int i = 0;
	bool answer = false;

	if (!player->ownedRegionSet.empty()) {
		//Take all tokens from the owned region, only leave one token
		for (auto i : player->ownedRegionSet) {
			player->addNumOfToken(mploader.regions[i].getUsefulContainToken());
			mploader.regions[i].resetContainToken(false);
			cout << "You owned " << player->getTokenNumber() << " tokens.\n";
		}
	}

	while (player->getTokenNumber() > 0) {
		cout << "Player " << player->getPlayerId() << ", please select a region to conquer( must be a region near a border or a region adjacent to the regions you own)" << endl;
		cin >> rnum;
		if (mploader.checkCanConquer(rnum, player->getPlayerId())) {
			localToken = mploader.regions[rnum].getContainToken() + 2;

			if (localToken > player->getTokenNumber()) {
				cout << "You don't have enough tokens. Please roll the dice.\n";
				i = dice.rollingResult();
				if ((i + player->getTokenNumber()) >= localToken) {
					if (mploader.regions[rnum].getOwnerId() != 100) {
						int c = mploader.regions[rnum].getOwnerId();
						ply[c - 1].minusRegion(rnum, ply, c);
						ply[c - 1].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
						mploader.regions[rnum].resetContainToken(false);
					}
					if (mploader.regions[rnum].getIsLostTribes()) {
						mploader.regions[rnum].minusContainToken(1);
						mploader.regions[rnum].setIsLostTribes(false);
					}
					player->addJoinRegion(rnum, ply, player->getPlayerId());
					mploader.regions[rnum].setOwnerID(player->getPlayerId());

					mploader.regions[rnum].addContainToken(player->getTokenNumber());
					player->resetNumOfToken();
					answer = true;
				}
				else {
					cout << "You can't conquer the region " << rnum << endl;
					break;
				}
			}

			else {
				if (mploader.regions[rnum].getOwnerId() != 100) {
					int c = mploader.regions[rnum].getOwnerId();
					ply[c - 1].minusRegion(rnum, ply, c);
					ply[c - 1].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
					mploader.regions[rnum].resetContainToken(false);
				}
				if (mploader.regions[rnum].getIsLostTribes()) {
					mploader.regions[rnum].minusContainToken(1);
					mploader.regions[rnum].setIsLostTribes(false);
				}

				player->addJoinRegion(rnum, ply, player->getPlayerId());
				mploader.regions[rnum].setOwnerID(player->getPlayerId());

				mploader.regions[rnum].addContainToken(localToken);
				player->minusNumOfToken(localToken);
			}

			cout << "You used " << localToken << " tokens to conquer this region" << ", and you have " << player->getTokenNumber() << " tokens left" << endl;

			if (answer == 1) {
				player->notifys(player);
			}

			if (answer == true)
				break;
		}
		else {
			cout << "Please choose a valid region number.\n";
		}
	}
}

void Defensive::redeployment(MapLoader& mploader, Player* player, vector<Player>& ply) {
	int c, t;
	string a;

	//Take all tokens from the owned region, only leave one token
	for (auto i : player->ownedRegionSet) {
		player->addNumOfToken(mploader.regions[i].getUsefulContainToken() - 1);
		mploader.regions[i].resetContainToken(false);
	}
	cout << "You got " << player->getTokenNumber() << " tokens on hand.\n";

	//start redeployment
	cout << "Player " << player->getPlayerId() << " owns the regions " << endl;
	for (auto i : player->ownedRegionSet) {
		cout << i << " ";
	}
	cout << endl;

	while (true && player->getTokenNumber() > 1) {
		cout << "Enter the region number you want to increate the defense\n";
		cin >> c;
		cout << "Enter the tokens you want to place.\n";
		cin >> t;
		if (mploader.checkBelongesTo(c, player->getPlayerId()) && (t <= player->getTokenNumber())) {
			player->minusCoins(t);
			mploader.regions[c].addContainToken(t);
			cout << "Region " << c << " contains " << mploader.regions[c].getContainToken() << " tokens.\n";
			cout << "Do u still want increase your defense? (y or n)";
			cin >> a;
			if (a != "y")
				break;
		}
		else
			cout << "The region is not belongs to you or the number of token is wrong.\n";
	}
}

void Defensive::score(MapLoader& mploader, Player* player, vector<Player>& ply, int ans) {
	for (auto r : player->race) {
		for (auto s : player->ownedRegionSet) {
			if (mploader.regions[s].getRegionType() == "Farmland"
				&& (r.getRaceName() == "Human")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getIsMagic()
				&& (r.getRaceName() == "Wizard")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (r.getRaceName() == "Orcs") {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getIsLairs()
				&& (r.getRaceName() == "Dwarves")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}

		}
	}
	for (auto p : player->powerbudge) {
		for (auto s : player->ownedRegionSet) {
			if (mploader.regions[s].getContainFortresses()
				&& p.getPowerName() == "Fortified") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Hill"
				&& p.getPowerName() == "Hill") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Forest"
				&& p.getPowerName() == "Forest") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Swamp"
				&& p.getPowerName() == "Swamp") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (p.getPowerName() == "Merchant") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (p.getPowerName() == "Pillaging") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
		}
		if (p.getPowerName() == "Alchemist") {
			player->setCoins(p.setVictoryCoins(player->getCoins()));
		}
		else if (p.getPowerName() == "Wealthy") {
			player->setCoins(p.setVictoryCoins(player->getCoins()));
		}

	}

	player->addCoins(player->ownedRegionSet.size());
	cout << "You owns " << player->getCoins() << " coins this turn.\n";

	if (ans == 1) {
		player->notifys(player);
	}
}

//================================================================================
//================================================================================

void Moderate::execute(MapLoader& mploader, Player* player, vector<Player>& ply, int numOfTurn) {
	player->setRegionTotalNum(mploader.regions.size());

	int numOfDecline = 0;
	string ans, ans2;

	if (numOfDecline == 0 || numOfTurn != 0) {
		cout << "Do you want to decline? (y or n)\n" << endl;
		cin >> ans;
		if (ans == "y") {
			chooseDecline(mploader, player, ply);
			numOfDecline++;
		}
		else {
			if (player->getTokenNumber() < 2) {
				cout << "Do you want to abandon your regions? (y or n)\n";
				cin >> ans2;
				if (ans2 == "y") {
					abandon(mploader, player, ply);
				}
			}

			if (!player->ownedRegionSet.empty()) {
				//Take all tokens from the owned region, only leave one token
				for (auto i : player->ownedRegionSet) {
					player->addNumOfToken(mploader.regions[i].getUsefulContainToken());
					cout << "You got " << player->getTokenNumber() << endl;
					mploader.regions[i].resetContainToken(false);
				}
			}
		}
	}
	else {
		if (player->getTokenNumber() < 2) {
			cout << "Do you want to abandon your regions? (y or n)\n";
			cin >> ans2;
			if (ans2 == "y") {
				abandon(mploader, player, ply);
			}
		}

		if (!player->ownedRegionSet.empty()) {
			//Take all tokens from the owned region, only leave one token
			for (auto i : player->ownedRegionSet) {
				player->addNumOfToken(mploader.regions[i].getUsefulContainToken());
				cout << "You got " << player->getTokenNumber() << endl;
				mploader.regions[i].resetContainToken(false);
			}
		}
	}
}

void Moderate::pickRace(Races &rs, PowerBudges &pb, Player* player) {
	if (!player->race.empty() && !player->powerbudge.empty()) {
		for (auto r : player->race) {
			r.setActiveCondition(false);
		}
		for (auto p : player->powerbudge) {
			p.setActiveCondition(false);
		}
	}

	player->addRace(rs);
	player->addPower(pb);
	//cout << player[id-1].getRaceVector().at(0).getRaceId() << endl;

	player->addNumOfToken(rs.getTokenNumber() + pb.getTokenNumber());

	cout << "You pick the race " << rs.getRaceName()
		<< " with special power " << pb.getPowerName()
		<< " owns " << player->getTokenNumber() << " tokens on hand \n";
}

void Moderate::chooseDecline(MapLoader& mploader, Player* player, vector<Player>& ply) {
	for (auto r : player->race) {
		r.setActiveCondition(false);
	}
	for (auto p : player->powerbudge) {
		p.setActiveCondition(false);
	}

	player->resetNumOfToken();

	for (auto s : player->ownedRegionSet) {
		mploader.regions[s].resetContainToken(true);
	}
}

void Moderate::abandon(MapLoader& mploader, Player* player, vector<Player>& ply) {
	int rid;
	string a;

	cout << "You owns ";
	for (auto i : player->ownedRegionSet) {
		cout << i << " ";
	}
	cout << endl;
	while (true) {
		cout << "Choose a region you want to abandon?\n";
		cin >> rid;
		if (mploader.checkCanConquer(rid, player->getPlayerId())) {
			player->addNumOfToken(mploader.regions[rid].getUsefulContainToken());
			mploader.regions[rid].resetContainToken(true);
			mploader.regions[rid].setOwnerID(100);
			player->minusRegion(rid, ply, player->getPlayerId());
			cout << "Now you have " << player->getTokenNumber() << " tokens.\n";
			cout << "Do u still want to abandon regions? (y or n)";
			cin >> a;
			if (a != "y")
				break;
		}
		else {
			cout << "The region u enter is not belongs to you\n";
			cout << "Please choose a valid number" << endl;
		}
	}
}

void Moderate::conquers(MapLoader& mploader, Player* player, vector<Player>& ply, int ans) {
	int rnum;
	int localToken;  //minimum tokens needed to conquer the region
	Dice dice;
	int i = 0;
	bool answer = false;

	if (!player->ownedRegionSet.empty()) {
		//Take all tokens from the owned region, only leave one token
		for (auto i : player->ownedRegionSet) {
			player->addNumOfToken(mploader.regions[i].getUsefulContainToken());
			mploader.regions[i].resetContainToken(false);
			cout << "You owned " << player->getTokenNumber() << " tokens.\n";
		}
	}

	while (player->getTokenNumber() > 0) {
		cout << "Player " << player->getPlayerId() << ", please select a region to conquer( must be a region near a border or a region adjacent to the regions you own)" << endl;
		cin >> rnum;
		if (mploader.checkCanConquer(rnum, player->getPlayerId())) {
			localToken = mploader.regions[rnum].getContainToken() + 2;

			if (localToken > player->getTokenNumber()) {
				cout << "You don't have enough tokens. Please roll the dice.\n";
				i = dice.rollingResult();
				if ((i + player->getTokenNumber()) >= localToken) {
					if (mploader.regions[rnum].getOwnerId() != 100) {
						int c = mploader.regions[rnum].getOwnerId();
						ply[c - 1].minusRegion(rnum, ply, c);
						ply[c - 1].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
						mploader.regions[rnum].resetContainToken(false);
					}
					if (mploader.regions[rnum].getIsLostTribes()) {
						mploader.regions[rnum].minusContainToken(1);
						mploader.regions[rnum].setIsLostTribes(false);
					}
					player->addJoinRegion(rnum, ply, player->getPlayerId());
					mploader.regions[rnum].setOwnerID(player->getPlayerId());

					mploader.regions[rnum].addContainToken(player->getTokenNumber());
					player->resetNumOfToken();
					answer = true;
				}
				else {
					cout << "You can't conquer the region " << rnum << endl;
					break;
				}
			}

			else {
				if (mploader.regions[rnum].getOwnerId() != 100) {
					int c = mploader.regions[rnum].getOwnerId();
					ply[c - 1].minusRegion(rnum, ply, c);
					ply[c - 1].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
					mploader.regions[rnum].resetContainToken(false);
				}
				if (mploader.regions[rnum].getIsLostTribes()) {
					mploader.regions[rnum].minusContainToken(1);
					mploader.regions[rnum].setIsLostTribes(false);
				}

				player->addJoinRegion(rnum, ply, player->getPlayerId());
				mploader.regions[rnum].setOwnerID(player->getPlayerId());

				mploader.regions[rnum].addContainToken(localToken);
				player->minusNumOfToken(localToken);
			}

			cout << "You used " << localToken << " tokens to conquer this region" << ", and you have " << player->getTokenNumber() << " tokens left" << endl;

			if (answer == 1) {
				player->notifys(player);
			}

			if (answer == true)
				break;
		}
		else {
			cout << "Please choose a valid region number.\n";
		}
	}
}

void Moderate::redeployment(MapLoader& mploader, Player* player, vector<Player>& ply) {
	int c, t;
	string a;

	//Take all tokens from the owned region, only leave one token
	for (auto i : player->ownedRegionSet) {
		player->addNumOfToken(mploader.regions[i].getUsefulContainToken() - 1);
		mploader.regions[i].resetContainToken(false);
	}
	cout << "You got " << player->getTokenNumber() << " tokens on hand.\n";

	//start redeployment
	cout << "Player " << player->getPlayerId() << " owns the regions " << endl;
	for (auto i : player->ownedRegionSet) {
		cout << i << " ";
	}
	cout << endl;

	while (true && player->getTokenNumber() > 1) {
		cout << "Enter the region number you want to increate the defense\n";
		cin >> c;
		cout << "Enter the tokens you want to place.\n";
		cin >> t;
		if (mploader.checkBelongesTo(c, player->getPlayerId()) && (t <= player->getTokenNumber())) {
			player->minusCoins(t);
			mploader.regions[c].addContainToken(t);
			cout << "Region " << c << " contains " << mploader.regions[c].getContainToken() << " tokens.\n";
			cout << "Do u still want increase your defense? (y or n)";
			cin >> a;
			if (a != "y")
				break;
		}
		else
			cout << "The region is not belongs to you or the number of token is wrong.\n";
	}
}

void Moderate::score(MapLoader& mploader, Player* player, vector<Player>& ply, int ans) {
	for (auto r : player->race) {
		for (auto s : player->ownedRegionSet) {
			if (mploader.regions[s].getRegionType() == "Farmland"
				&& (r.getRaceName() == "Human")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getIsMagic()
				&& (r.getRaceName() == "Wizard")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (r.getRaceName() == "Orcs") {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getIsLairs()
				&& (r.getRaceName() == "Dwarves")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}

		}
	}
	for (auto p : player->powerbudge) {
		for (auto s : player->ownedRegionSet) {
			if (mploader.regions[s].getContainFortresses()
				&& p.getPowerName() == "Fortified") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Hill"
				&& p.getPowerName() == "Hill") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Forest"
				&& p.getPowerName() == "Forest") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Swamp"
				&& p.getPowerName() == "Swamp") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (p.getPowerName() == "Merchant") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (p.getPowerName() == "Pillaging") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
		}
		if (p.getPowerName() == "Alchemist") {
			player->setCoins(p.setVictoryCoins(player->getCoins()));
		}
		else if (p.getPowerName() == "Wealthy") {
			player->setCoins(p.setVictoryCoins(player->getCoins()));
		}

	}

	player->addCoins(player->ownedRegionSet.size());
	cout << "You owns " << player->getCoins() << " coins this turn.\n";

	if (ans == 1) {
		player->notifys(player);
	}
}

//================================================================================
//================================================================================

void Random::execute(MapLoader& mploader, Player* player, vector<Player>& ply, int numOfTurn) {
	player->setRegionTotalNum(mploader.regions.size());

	int s;
	string ans;

	if (numOfDecline == 0 || numOfTurn != 1) {
		srand((unsigned)time(0));
		s = rand() % 2;
		if (s == 0) {
			chooseDecline(mploader, player, ply);
			numOfDecline = 1;
		}
		else {
			if (player->getTokenNumber() < 2) {
				cout << "Do you want to abandon your regions? (y or n)\n";
				cin >> ans;
				if (ans == "y") {
					abandon(mploader, player, ply);
				}
			}
		}
	}
	else {
		if (player->getTokenNumber() < 2) {
			cout << "Do you want to abandon your regions? (y or n)\n";
			cin >> ans;
			if (ans == "y") {
				abandon(mploader, player, ply);
			}
		}
	}
}

void Random::pickRace(Races &rs, PowerBudges &pb, Player* player) {
	if (!player->race.empty() && !player->powerbudge.empty()) {
		for (auto r : player->race) {
			r.setActiveCondition(false);
		}
		for (auto p : player->powerbudge) {
			p.setActiveCondition(false);
		}
	}

	player->addRace(rs);
	player->addPower(pb);
	//cout << player[id-1].getRaceVector().at(0).getRaceId() << endl;

	player->addNumOfToken(rs.getTokenNumber() + pb.getTokenNumber());

	cout << "You pick the race " << rs.getRaceName()
		<< " with special power " << pb.getPowerName()
		<< " owns " << player->getTokenNumber() << " tokens on hand \n";
}

void Random::chooseDecline(MapLoader& mploader, Player* player, vector<Player>& ply) {
	for (auto r : player->race) {
		r.setActiveCondition(false);
	}
	for (auto p : player->powerbudge) {
		p.setActiveCondition(false);
	}

	player->resetNumOfToken();

	for (auto s : player->ownedRegionSet) {
		mploader.regions[s].resetContainToken(true);
	}
}

void Random::abandon(MapLoader& mploader, Player* player, vector<Player>& ply) {
	int rid;
	string a;

	cout << "You owns ";
	for (auto i : player->ownedRegionSet) {
		cout << i << " ";
	}
	cout << endl;
	while (true) {
		cout << "Choose a region you want to abandon?\n";
		cin >> rid;
		if (mploader.checkCanConquer(rid, player->getPlayerId())) {
			player->addNumOfToken(mploader.regions[rid].getUsefulContainToken());
			mploader.regions[rid].resetContainToken(true);
			mploader.regions[rid].setOwnerID(100);
			player->minusRegion(rid, ply, player->getPlayerId());
			cout << "Now you have " << player->getTokenNumber() << " tokens.\n";
			cout << "Do u still want to abandon regions? (y or n)";
			cin >> a;
			if (a != "y")
				break;
		}
		else {
			cout << "The region u enter is not belongs to you\n";
			cout << "Please choose a valid number" << endl;
		}
	}
}

void Random::conquers(MapLoader& mploader, Player* player, vector<Player>& ply, int ans) {
	int rnum;
	int localToken;  //minimum tokens needed to conquer the region
	Dice dice;
	int i = 0;
	bool answer = false;

	if (!player->ownedRegionSet.empty()) {
		//Take all tokens from the owned region, only leave one token
		for (auto i : player->ownedRegionSet) {
			player->addNumOfToken(mploader.regions[i].getUsefulContainToken());
			mploader.regions[i].resetContainToken(false);
			cout << "You owned " << player->getTokenNumber() << " tokens.\n";
		}
	}

	while (player->getTokenNumber() > 0) {
		cout << "Player " << player->getPlayerId() << ", please select a region to conquer( must be a region near a border or a region adjacent to the regions you own)" << endl;
		cin >> rnum;
		if (mploader.checkCanConquer(rnum, player->getPlayerId())) {
			localToken = mploader.regions[rnum].getContainToken() + 2;

			if (localToken > player->getTokenNumber()) {
				cout << "You don't have enough tokens. Please roll the dice.\n";
				i = dice.rollingResult();
				if ((i + player->getTokenNumber()) >= localToken) {
					if (mploader.regions[rnum].getOwnerId() != 100) {
						int c = mploader.regions[rnum].getOwnerId();
						ply[c - 1].minusRegion(rnum, ply, c);
						ply[c - 1].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
						mploader.regions[rnum].resetContainToken(false);
					}
					if (mploader.regions[rnum].getIsLostTribes()) {
						mploader.regions[rnum].minusContainToken(1);
						mploader.regions[rnum].setIsLostTribes(false);
					}
					player->addJoinRegion(rnum, ply, player->getPlayerId());
					mploader.regions[rnum].setOwnerID(player->getPlayerId());

					mploader.regions[rnum].addContainToken(player->getTokenNumber());
					player->resetNumOfToken();
					answer = true;
				}
				else {
					cout << "You can't conquer the region " << rnum << endl;
					break;
				}
			}

			else {
				if (mploader.regions[rnum].getOwnerId() != 100) {
					int c = mploader.regions[rnum].getOwnerId();
					ply[c - 1].minusRegion(rnum, ply, c);
					ply[c - 1].addNumOfToken(mploader.regions[rnum].getContainToken() - 1);
					mploader.regions[rnum].resetContainToken(false);
				}
				if (mploader.regions[rnum].getIsLostTribes()) {
					mploader.regions[rnum].minusContainToken(1);
					mploader.regions[rnum].setIsLostTribes(false);
				}

				player->addJoinRegion(rnum, ply, player->getPlayerId());
				mploader.regions[rnum].setOwnerID(player->getPlayerId());

				mploader.regions[rnum].addContainToken(localToken);
				player->minusNumOfToken(localToken);
			}

			cout << "You used " << localToken << " tokens to conquer this region" << ", and you have " << player->getTokenNumber() << " tokens left" << endl;

			if (answer == 1) {
				player->notifys(player);
			}

			if (answer == true)
				break;
		}
		else {
			cout << "Please choose a valid region number.\n";
		}
	}
}

void Random::redeployment(MapLoader& mploader, Player* player, vector<Player>& ply) {
	int c, t;
	string a;

	//Take all tokens from the owned region, only leave one token
	for (auto i : player->ownedRegionSet) {
		player->addNumOfToken(mploader.regions[i].getUsefulContainToken() - 1);
		mploader.regions[i].resetContainToken(false);
	}
	cout << "You got " << player->getTokenNumber() << " tokens on hand.\n";

	//start redeployment
	cout << "Player " << player->getPlayerId() << " owns the regions " << endl;
	for (auto i : player->ownedRegionSet) {
		cout << i << " ";
	}
	cout << endl;

	while (true && player->getTokenNumber() > 1) {
		cout << "Enter the region number you want to increate the defense\n";
		cin >> c;
		cout << "Enter the tokens you want to place.\n";
		cin >> t;
		if (mploader.checkBelongesTo(c, player->getPlayerId()) && (t <= player->getTokenNumber())) {
			player->minusCoins(t);
			mploader.regions[c].addContainToken(t);
			cout << "Region " << c << " contains " << mploader.regions[c].getContainToken() << " tokens.\n";
			cout << "Do u still want increase your defense? (y or n)";
			cin >> a;
			if (a != "y")
				break;
		}
		else
			cout << "The region is not belongs to you or the number of token is wrong.\n";
	}
}

void Random::score(MapLoader& mploader, Player* player, vector<Player>& ply, int ans) {
	for (auto r : player->race) {
		for (auto s : player->ownedRegionSet) {
			if (mploader.regions[s].getRegionType() == "Farmland"
				&& (r.getRaceName() == "Human")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getIsMagic()
				&& (r.getRaceName() == "Wizard")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (r.getRaceName() == "Orcs") {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getIsLairs()
				&& (r.getRaceName() == "Dwarves")) {
				player->setCoins(r.setVictoryCoins(player->getCoins()));
			}

		}
	}
	for (auto p : player->powerbudge) {
		for (auto s : player->ownedRegionSet) {
			if (mploader.regions[s].getContainFortresses()
				&& p.getPowerName() == "Fortified") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Hill"
				&& p.getPowerName() == "Hill") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Forest"
				&& p.getPowerName() == "Forest") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (mploader.regions[s].getRegionType() == "Swamp"
				&& p.getPowerName() == "Swamp") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (p.getPowerName() == "Merchant") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
			else if (p.getPowerName() == "Pillaging") {
				player->setCoins(p.setVictoryCoins(player->getCoins()));
			}
		}
		if (p.getPowerName() == "Alchemist") {
			player->setCoins(p.setVictoryCoins(player->getCoins()));
		}
		else if (p.getPowerName() == "Wealthy") {
			player->setCoins(p.setVictoryCoins(player->getCoins()));
		}

	}

	player->addCoins(player->ownedRegionSet.size());
	cout << "You owns " << player->getCoins() << " coins this turn.\n";

	if (ans == 1) {
		player->notifys(player);
	}
}

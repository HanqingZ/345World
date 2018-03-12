#include <iostream>
#include <string>

#include "Player.h"
#include "Races.h"
#include "PowerBudges.h"
//#include "MapLoader.h"


using namespace std;

Player::Player() {
	this->id = 0;
	this->coinOwn = 5;
	this->numOfTokenOwn = 0;
	this->race.clear();
	this->powerbudge.clear();
	this->ownedRegionSet.clear();
}

Player::Player(int userId) {
	this->id = userId;
	this->coinOwn = 5;
	this->numOfTokenOwn = 0;
	this->race.clear();
	this->powerbudge.clear();
	this->ownedRegionSet.clear();
}

Player::~Player() {

}

/*
**	Part 2 Player pick a Race and Super Power Combo
**	If player already have a combo,
**	he/she should set previous to be decline
**	Once per Player
*/
void Player::pick_race(Races& rs, PowerBudges& ps) {
	if (!race.empty() && !powerbudge.empty()) {
		for (auto r : race) {
			r.setActiveCondition(false);
		}
		for (auto p : powerbudge) {
			p.setActiveCondition(false);
		}
	}
	race.push_back(rs);
	powerbudge.push_back(ps);
	this->numOfTokenOwn = rs.getTokenNumber() + ps.getTokenNumber();
	cout << "You pick the race " << rs.getRaceName()
		<< " with special power " << ps.getPowerName()
		<< " owns " << numOfTokenOwn << " tokens on hand ";

}

/*
**	Part 3 and Part 5 Conquers some regions
**	Run once per Player in each turn
*/
void Player::conquers(MapLoader &mploader, int numberOfTurn) {
	int numOfToken;
	bool question = true;

	while (question) {
		// First turn Conquer or decline previous race
		if (numberOfTurn == 1 || players[id].ownedRegionSet.empty()) {
			mploader.printOnlySideRegion();
		}
		//Following turn Conquer
		else {
			cout << "You own:" << endl;
			for (auto i : players[id].ownedRegionSet) {
				mploader.regions[i].shown();
			}
			cout << "Please choose one region which's surrounding you want to pick.\n";
			cin >> regionId;

			mploader.printSurroungdingRegion(regionId);
		}

		cout << "Please enter the region number you want to conquer." << endl;
		cin >> regionId;

		int localToken = mploader.regions[regionId].getContainToken();
		cout << "This regions has " << localToken << " tokens." << endl;
		cout << "Your have " << numOfTokenOwn << " tokens on hand." << endl;
		cout << "Please choose the number of token you want to place.\n"
			<< "(should place two tokens bigger to get this regions)" << endl;
		cin >> numOfToken;

		//Final Conquest/Reinforcement Die Roll
		if ((mploader.regions[regionId].getContainToken() + 2) >= numOfToken) {
			cout << "You have less tokens on hand." << endl;
			cout << "You can row the dice." << endl;
			int i = d.rollingResult();
			cout << "You got " << i << endl;
			numOfToken += i;
			
			question = false;
		}

		if ((mploader.regions[regionId].getContainToken() + 2) <= numOfToken) {
			this->numOfTokenOwn -= numOfToken;
			//Check whether this region has been conquered
			if (mploader.regions[regionId].getOwnerId() != 100) {
				int k = mploader.regions[regionId].getOwnerId();
				players[k].ownedRegionSet.remove(regionId);
				if (mploader.regions[regionId].getRegionType() == "Mountain") {
					mploader.regions[regionId].minusContainToken(localToken - 1);
				}
				else {
					mploader.regions[regionId].minusContainToken(localToken);
				}
			}
			mploader.regions[regionId].setOwnerID(id);
			if (mploader.regions[regionId].getIsLostTribes()) {
				mploader.regions[regionId].minusContainToken(1);
				mploader.regions[regionId].setIsLostTribes(false);
			}
			mploader.regions[regionId].addContainToken(numOfToken);
			players[id].ownedRegionSet.push_back(regionId);
			cout << "Success Conquer! \n";
		}

		
	}
	/*
	if (numberOfTurn == 1) {
		int numOfToken;
		bool question = true;

		//For the special power "Berserk", it can roll dice everytime before conquer
		if (this->powerbudge.getPowerId() == 1) {
			cout << "You can roll the dice every time." << endl;

			int diceResult = d.rollingResult();
			cout << "You got " << diceResult << endl;

			mploader.printOnlySideRegion();

			cout << "Please enter the region number you want to conquer." << endl;
			cin >> regionId;

			//check whether some players set this region into immune status.
			while (mploader.regions[regionId].getImmuneRegion() == true
				|| mploader.regions[regionId].getRegionType() == "Lake") {
				cout << "This region can't be conquer, please choose another region." << endl;
				cin >> regionId;
			}

			cout << "This regions has " << mploader.regions[regionId].getContainToken()
				<< " tokens." << endl;
			cout << "Your have " << numOfTokenOwn << " tokens on hand." << endl;
			cout << "Please choose the number of token you want to place.\n"
				<< "(should place two tokens bigger to get this regions)" << endl;
			cin >> numOfToken;

		}

		else {
			while (question) {
				if (players[id].ownedRegionSet.empty()) {
					mploader.printOnlySideRegion();
				}

				cout << "Please enter the region number you want to conquer." << endl;
				cin >> regionId;

				while (mploader.regions[regionId].getImmuneRegion() == true 
					|| mploader.regions[regionId].getRegionType() == "Lake") {
					cout << "This region can't be conquer, please choose another region." << endl;
					cin >> regionId;
				}

				cout << "This regions has " << mploader.regions[regionId].getContainToken()
					<< " tokens." << endl;
				cout << "Your have " << numOfTokenOwn << " tokens on hand." << endl;
				cout << "Please choose the number of token you want to place.\n"
					<< "(should place two tokens bigger to get this regions)" << endl;
				cin >> numOfToken;



				if (mploader.regions[regionId].getContainToken() + 2 >= numOfToken
					&& numOfTokenOwn >= numOfToken) {
					cout << "You have less tokens on hand." << endl;
					cout << "You can row the dice." << endl;
					int i = d.rollingResult();
					cout << "You got " << i << endl;
					numOfToken += i;

					question = false;
				}

				this->numOfTokenOwn -= numOfToken;
				if (mploader.regions[regionId].getOwnerId() != 0) {
					int k = mploader.regions[regionId].getOwnerId();
					players[k].ownedRegionSet.remove(regionId);
				}
				mploader.regions[regionId].setOwnerID(id);
				players[id].ownedRegionSet.push_back(regionId);
			}
		}
	}
	*/

}

/*
**	Part 3 and Part 5 Redeployment
*/
void Player::redployment(MapLoader &mploader) {
	int rid;
	int regionToken = 0;
	int regionToken2 = 10;
	bool answer1 = true;
	bool answer2 = true;
	string l;

	cout << "Now you can replace your tokens on the map." << endl;

	cout << "Player " << id << " owns the regions "  << endl;
	for (auto i : players[id].ownedRegionSet) {
		cout << i << " ";
	}
	cout << endl;

	while (answer1) {
		cout << "Please enter the Region ID number that you want to remove tokens from: \n";
		cin >> rid;

		cout << "The region " << rid << " contains "
			<< mploader.regions[rid].getContainToken() << " tokens." << endl;

		while (regionToken < 1) {
			cout << "Enter the tokens you want to remain on this region."
				<< "(at least one token on the region)" << endl;
			cin >> regionToken;
		}

		mploader.regions[rid].minusContainToken(regionToken);
		this->numOfTokenOwn += regionToken;

		cout << "Do u still want to remove your tokens from the map? (y or n)";
		cin >> l;

		if (l != "y") {
			answer1 = false;
		}
	}

	while (answer2) {
		cout << "Please enter the Region ID number that you want to place tokens from: \n";
		cin >> rid;

		cout << "The region " << rid << " contains "
			<< mploader.regions[rid].getContainToken() << " tokens." << endl;

		cout << "You owns " << numOfTokenOwn << " tokens on hand." << endl;

		while (regionToken2 != 0 && regionToken2 > numOfTokenOwn) {
			cout << "Enter the tokens you want to be placed on this region."
				<< "(same or less than the tokens on your hand)" << endl;
			cin >> regionToken2;
		}

		mploader.regions[rid].addContainToken(regionToken);
		this->numOfTokenOwn -= regionToken;

		cout << "Do u still want to add your tokens to the map? (y or n)";
		cin >> l;

		if (l != "y") {
			answer2 = false;
		}
	}
}

/*
**	Part 3 and Part 6 Scoring Victory Coins
*/
void Player::score(MapLoader &mploader) {
	int forest = 0; 
	int farm = 0;
	int hill = 0;
	int lairs = 0;
	int magic = 0;
	int fortress = 0; 
	int all = 0;

	for (auto r : race) {
		for (auto s : players[id].ownedRegionSet) {
			if (mploader.regions[s].getRegionType() == "Farmland"
				&& (r.getRaceName() == "Human")) {
				r.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getIsMagic()
				&& (r.getRaceName() == "Wizard")) {
				r.setVictoryCoins(this->coinOwn);
			}
			else if (r.getRaceName() == "Orcs") {
				r.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getIsLairs()
				&& (r.getRaceName() == "Dwarves")) {
				r.setVictoryCoins(this->coinOwn);
			}

		}
	}
	for (auto p : powerbudge) {
		for (auto s : players[id].ownedRegionSet) {
			if(mploader.regions[s].getContainFortresses()
				&& p.getPowerName() == "Fortified"){
				p.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getRegionType() == "Hill"
				&& p.getPowerName() == "Hill") {
				p.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getRegionType() == "Forest"
				&& p.getPowerName() == "Forest") {
				p.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getRegionType() == "Swamp"
				&& p.getPowerName() == "Swamp") {
				p.setVictoryCoins(this->coinOwn);
			}
			else if (p.getPowerName() == "Merchant") {
				p.setVictoryCoins(this->coinOwn);
			}
			else if (p.getPowerName() == "Pillaging") {
				p.setVictoryCoins(this->coinOwn);
			}
		}
		if (p.getPowerName() == "Alchemist") {
			p.setVictoryCoins(this->coinOwn);
		}
		else if (p.getPowerName() == "Wealthy") {
			p.setVictoryCoins(this->coinOwn);
		}

	}
		
	this->coinOwn += ownedRegionSet.size();

}

void Player::chooseDecline(MapLoader &mploader) {
	for (auto r : race) {
		r.setActiveCondition(false);
	}
	for (auto p : powerbudge) {
		p.setActiveCondition(false);
	}

	for (auto s : players[id].ownedRegionSet) {
		if (mploader.regions[s].getRegionType() == "Mountain") {
			mploader.regions[s].resetContainToken();
			mploader.regions[s].addContainToken(1);
		}
		else {
			mploader.regions[s].resetContainToken();
		}
	}
}

//==================================================================

void Player::minusCoins(int coins) {
	this->coinOwn -= coins;
}

void Player::addCoins(int coins) {
	this->coinOwn += coins;
}

void Player::setNumOfToken(int token) {
	this->numOfTokenOwn += token;
}

int Player::getCoins() {
	return this->coinOwn;
}

int Player::getTokenNumber() {
	return this->numOfTokenOwn;
}

int Player::getPlayerId() {
	return this->id;
}

#include <iostream>
#include <string>

#include "Player.h"
#include "Races.h"
#include "PowerBudges.h"
//#include "MapLoader.h"


using namespace std;

Player::Player() {
	this->id = 0;
	this->isComputer = false;
	this->coinOwn = 5;
	this->numOfTokenOwn = 0;
	this->race.clear();
	this->powerbudge.clear();
	this->ownedRegionSet.clear();
}

Player::Player(int userId) {
	this->id = userId;
	this->isComputer = false;
	this->coinOwn = 5;
	this->numOfTokenOwn = 0;
	this->race.clear();
	this->powerbudge.clear();
	this->ownedRegionSet.clear();
}

Player::~Player() {

}

/*
void Player::setStrategy(MapLoader &mploader, int numberOfTurn, vector<Player> &player) {
	cout << "You don't have strategy to choose.\n";
}
*/

/*
**	Player pick a Race and Super Power Combo
**	If player already have a combo, he/she should set previous to be decline
**	Once per Player
*/
void Player::pick_race(Races& rs, PowerBudges& ps, vector<Player> &player) {
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
	//cout << player[id-1].getRaceVector().at(0).getRaceId() << endl;

	this->numOfTokenOwn += rs.getTokenNumber() + ps.getTokenNumber();

	cout << "You pick the race " << rs.getRaceName()
		<< " with special power " << ps.getPowerName()
		<< " owns " << numOfTokenOwn << " tokens on hand \n";

}

//Conquers some regions and Run once per Player in each turn
void Player::conquers(MapLoader &mploader, int numberOfTurn, vector<Player> &player) {
	
	this->setRegionTotalNum(mploader.regions.size());
//	playerTurn = numberOfTurn;
	int numOfToken; //input
	bool question = true;
	bool check = false;
	int regionId;
	if (!player[id-1].ownedRegionSet.empty()) {
		for (auto i : player[id-1].ownedRegionSet) {
			numOfTokenOwn += mploader.regions[i].getUsefulContainToken();
			mploader.regions[i].resetContainToken(false);
		}
	}
	while (this->numOfTokenOwn >= 1) {
		cout << "Player " << getPlayerId() << ", please select a region to conquer( must be a region near a border or a region adjacent to the regions you own)" << endl;
		cin >> regionId;
		check = mploader.checkCanConquer(regionId, getPlayerId());
		if (check == true) {
			int numOfTokensNeededToConquerRegion = mploader.regions[regionId].getContainToken();
			numOfTokensNeededToConquerRegion += 2;
			int playerToken = numOfTokenOwn;
			if (numOfTokensNeededToConquerRegion <= numOfTokenOwn) {
				//if there is a token from a another player is here in this region, 
				//the number of race token is decreased by 1, and all the other pieces are returned to the previous owner.
				int oldeownerId = mploader.regions[regionId].getOwnerId();
				if (oldeownerId != 100) {
					int oldPlayerTokenNum = mploader.regions[regionId].getUsefulContainToken();
					player[oldeownerId - 1].addNumOfToken(oldPlayerTokenNum);	
					mploader.regions[regionId].resetContainToken(true);
					player[oldeownerId - 1].minusRegion(regionId, player, getPlayerId());
				}
				//add tokens and player id in this region
				mploader.regions[regionId].setOwnerID(this->id);
			
				mploader.regions[regionId].addContainToken(numOfTokensNeededToConquerRegion);
				this->addJoinRegion(regionId, player, getPlayerId());
				//decrease token number for the current player
		 
				this->minusNumOfToken(numOfTokensNeededToConquerRegion);
				 
				cout << "You used " << numOfTokensNeededToConquerRegion << " tokens to conquer this region" << ", and you have " << this->getTokenNumber() << " tokens left" << endl;
			}
			else {
				//play dice here, and decide if the user can conquer the region or not
				int diceNum = d.rollingResult();
				int diceToken = numOfTokenOwn + diceNum;
				if (numOfTokensNeededToConquerRegion <= diceToken) {
					//if three is a token from a another player is here in this region, 
					//the number of race token is decreased by 1, and all the other pieces are returned to the previous owner.
					int oldeownerId = mploader.regions[regionId].getOwnerId();
					if (oldeownerId != 100) {
						int oldPlayerTokenNum = mploader.regions[regionId].getUsefulContainToken();
						player[oldeownerId - 1].addNumOfToken(oldPlayerTokenNum );
						mploader.regions[regionId].resetContainToken(true);
					}
					//add tokens and player id in this region
					mploader.regions[regionId].setOwnerID(this->id);

					mploader.regions[regionId].addContainToken(numOfTokensNeededToConquerRegion);
					this->addJoinRegion(regionId, player, getPlayerId());
					//decrease token number for the current player

					this->minusNumOfToken(numOfTokensNeededToConquerRegion);

					cout << "You used " << numOfTokensNeededToConquerRegion << " tokens to conquer this region" << ", and you have " << this->getTokenNumber() << " tokens left" << endl;
					break;
				}
				else {
					cout << "You didn't get enough number from dice" << endl;
					break;
				}
			}
				

		}//if for checking
		else {
			cerr << "This is not a valid region" << endl;
		}
	 }
}

//Redeployment
void Player::redployment(MapLoader &mploader, vector<Player>& player) {
	int rid;
	int regionToken2 = 20;
	string l;

	cout << "Now you can replace your tokens on the map." << endl;

	//Take all tokens from the owned region, only leave one token
	for (auto i : player[id-1].ownedRegionSet) {
		numOfTokenOwn += mploader.regions[i].getUsefulContainToken();
		mploader.regions[i].resetContainToken(false);
	}

	cout << "Player " << id << " owns the regions "  << endl;
	for (auto i : player[id-1].ownedRegionSet) {
		cout << i << " ";
	}
	cout << endl;

	while (true) {
		while (true) {
			cout << "Please enter the Region ID number that you want to place tokens from: \n";
			cin >> rid;
			if (mploader.checkBelongesTo(rid, id)) {
				break;
			}
			cout << "This region is not belong to you.\n";
		}
		cout << "The region " << rid << " contains "
			<< mploader.regions[rid].getContainToken() << " tokens." << endl;

		cout << "You owns " << numOfTokenOwn << " tokens on hand." << endl;

		while (true) {
			cout << "Enter the tokens you want to be placed on this region."
				<< "(same or less than the tokens on your hand)" << endl;
			cin >> regionToken2;
			if (regionToken2 <= numOfTokenOwn) {
				break;
			}
			cout << "Please re-enter the tokens you want to be placed on this region.\n";
		}

		mploader.regions[rid].addContainToken(regionToken2);
		this->numOfTokenOwn -= regionToken2;

		cout << "Do u still want to add your tokens to the map? (y or n)";
		cin >> l;

		if (l != "y") {
			break;
		}
	}
}

//Scoring Victory Coins
void Player::score(MapLoader &mploader, vector<Player>& player) {
	int forest = 0; 
	int farm = 0;
	int hill = 0;
	int lairs = 0;
	int magic = 0;
	int fortress = 0; 
	int all = 0;

	for (auto r : player[id].race) {
		for (auto s : player[id].ownedRegionSet) {
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
	for (auto p : player[id].powerbudge) {
		for (auto s : player[id].ownedRegionSet) {
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
	cout << "You owns " << coinOwn << " coins.\n";

}

bool Player::chooseDecline(MapLoader &mploader, int numOfTurn, vector<Player>& player) {
	if (numOfDecline == 0) {
		for (auto r : race) {
			r.setActiveCondition(false);
		}
		for (auto p : powerbudge) {
			p.setActiveCondition(false);
		}

		for (auto s : player[id].ownedRegionSet) {
			mploader.regions[s].resetContainToken(true);
		}
		numOfDecline++;
		return true;
	}
	else {
		cout << "You can't decline!\n";
		return false;
	}
}

//==================================================================

void Player::minusCoins(int coins) {
	this->coinOwn -= coins;
	//Notify(this);
}

void Player::addCoins(int coins) {
	this->coinOwn += coins;
	//Notify(this);
}

void Player::addNumOfToken(int token) {
	this->numOfTokenOwn += token;
	//Notify(this);
}

void Player::minusNumOfToken(int token) {
	this->numOfTokenOwn -= token;
	//Notify(this);
}

void Player::resetNumOfToken() {
	this->numOfTokenOwn = 0;
	//Notify(this);
}

//void Player::addRace(Races &rs) {
//	race.push_back(rs);
//	//Notify(this);
//}

//void Player::addPower(PowerBudges pb) {
//	powerbudge.push_back(pb);
//	//Notify(this);
//}

void Player::addJoinRegion(int rg, vector<Player>& players,int playerID) {
	players[playerID - 1].GetList();
	players[playerID-1].GetList().push_back(rg);
	int i = ownedRegionSet.size();
	players[playerID-1].setPlayerRegionSize(i);
	//Notify(regionTotalNum, this);
	cout<< ownedRegionSet.size() <<endl;
	NotifyAll(regionTotalNum, players);
}
void Player::minusRegion(int rg, vector<Player>& players, int playerID) {
	/*for (size_t i = 0; i < ownedRegionSet.size(); i++) {
		if(ownedRegionSet.at(i)==rg)
			ownedRegionSet.erase(i);
	}*/
	cout << ownedRegionSet.size()<<"shgdfsdhjgfds" << endl;
	for (auto i : ownedRegionSet) {
		if (i == rg)
			players[playerID-1].GetList().remove(i);
	}
	cout << ownedRegionSet.size() << "shgdfsdhjgfds" << endl;
	//Notify(regionTotalNum, this);
	int i = ownedRegionSet.size();
	players[playerID - 1].setPlayerRegionSize(i);
	NotifyAll(regionTotalNum, players);
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

bool Player::getIsComputer() {
	return this->isComputer;
}


//vector<Region> Player::getOwnedRegion(int) {

//}


void Player::shown() {
	cout << "Your id is " << id << ", and your token number is " 
		<< numOfTokenOwn << endl;
}

int Player::getPlayerRegionSize() {
	return this->playerRegionSize;
}
void Player::setPlayerRegionSize(int playerRegionSize) {
	this->playerRegionSize = playerRegionSize;
}
list<int> Player::GetList() {
	return ownedRegionSet;
}
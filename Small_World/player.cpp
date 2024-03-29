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
	this->strategyType = "";
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

	int q;
	while (true) {
		try {
			cout << "Please choose a strategy mode (1 to 4)\n";
			cin >> q;
			if (q > 4 || q < 1)
				throw q;
			else
				break;
		}
		catch (int x) {
			cout << "Please enter a number between 1 and 4.\n";
		}
	}

	switch (q){
	case 1:
		cout << "You choose aggressive.\n";
		strategyType = "Aggressive";
		break;
	case 2:
		cout << "You choose defensive.\n";
		strategyType = "Defensive";
		break;
	case 3:
		cout << "You choose moderate.\n";
		strategyType = "Moderate";
		break;
	case 4:
		cout << "You choose random.\n";
		strategyType = "Random";
		break;
	}
}

Player::~Player() {

}

/*
**	Player pick a Race and Super Power Combo
**	If player already have a combo, he/she should set previous to be decline
*/
/*
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
void Player::conquers(MapLoader &mploader, int numberOfTurn, vector<Player> &player, int answer) {
	
	this->setRegionTotalNum(mploader.regions.size());
	int numOfToken = 0; //input
	bool question = true;
	bool check = false;
	int regionId;
	if (!player[id-1].ownedRegionSet.empty()) {
		for (auto i : player[id-1].ownedRegionSet) {
			numOfTokenOwn += (mploader.regions[i].getUsefulContainToken() - 1);
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
					player[oldeownerId - 1].addNumOfToken(oldPlayerTokenNum - 1);	
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
				if (answer == 1) {
					Notify(this);
				}
				
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
//numOfTokenOwn += mploader.regions[i].getUsefulContainToken();

		this->numOfTokenOwn += mploader.regions[i].getUsefulContainToken();
		cout << "You got " << numOfTokenOwn << endl;
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
void Player::score(MapLoader &mploader, vector<Player>& player,int victoryCoinOAnwser) {

	for (auto r : player[id - 1].race) {
		for (auto s : player[id - 1].ownedRegionSet) {
			if (mploader.regions[s].getRegionType() == "Farmland"
				&& (r.getRaceName() == "Human")) {
				this->coinOwn = r.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getIsMagic()
				&& (r.getRaceName() == "Wizard")) {
				this->coinOwn = r.setVictoryCoins(this->coinOwn);
			}
			else if (r.getRaceName() == "Orcs") {
				this->coinOwn = r.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getIsLairs()
				&& (r.getRaceName() == "Dwarves")) {
				this->coinOwn = r.setVictoryCoins(this->coinOwn);
			}

		}
	}
	for (auto p : player[id - 1].powerbudge) {
		for (auto s : player[id - 1].ownedRegionSet) {
			if(mploader.regions[s].getContainFortresses()
				&& p.getPowerName() == "Fortified"){
				this->coinOwn = p.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getRegionType() == "Hill"
				&& p.getPowerName() == "Hill") {
				this->coinOwn = p.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getRegionType() == "Forest"
				&& p.getPowerName() == "Forest") {
				this->coinOwn = p.setVictoryCoins(this->coinOwn);
			}
			else if (mploader.regions[s].getRegionType() == "Swamp"
				&& p.getPowerName() == "Swamp") {
				this->coinOwn = p.setVictoryCoins(this->coinOwn);
			}
			else if (p.getPowerName() == "Merchant") {
				this->coinOwn = p.setVictoryCoins(this->coinOwn);
			}
			else if (p.getPowerName() == "Pillaging") {
				this->coinOwn = p.setVictoryCoins(this->coinOwn);
			}
		}
		if (p.getPowerName() == "Alchemist") {
			this->coinOwn = p.setVictoryCoins(this->coinOwn);
		}
		else if (p.getPowerName() == "Wealthy") {
			this->coinOwn = p.setVictoryCoins(this->coinOwn);
		}

	}
		
	this->coinOwn += ownedRegionSet.size();
	cout << "You owns " << coinOwn << " coins.\n";
	if (victoryCoinOAnwser == 1) {
		Notify(this);
	}
}

bool Player::chooseDecline(MapLoader &mploader, int numOfTurn, vector<Player>& player) {
	if (numOfDecline == 0) {
		for (auto r : race) {
			r.setActiveCondition(false);
		}
		for (auto p : powerbudge) {
			p.setActiveCondition(false);
		}

		player[id - 1].resetNumOfToken();

		for (auto s : player[id - 1].ownedRegionSet) {
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
*/

//==================================================================

void Player::minusCoins(int coins) {
	this->coinOwn -= coins;
	//Notify(this);
}

void Player::addCoins(int coins) {
	this->coinOwn += coins;
	//Notify(this);
}

void Player::setCoins(int coins) {
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
	ownedRegionSet.push_back(rg);
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
			ownedRegionSet.remove(i);
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

string Player::getStrategyName() {
	return this->strategyType;
}


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

void Player::notifys(Player* ply) {
	Notify(ply);
}
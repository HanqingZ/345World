#include <iostream>
#include <string>

#include "Player.h"
#include "Races.h"
#include "PowerBudges.h"
//#include "MapLoader.h"


using namespace std;

Player::Player() {
	id = 0;
	coinOwn = 5;
	numOfTokenOwn = 0;
}

Player::Player(int userId) {
	this->id = userId;
	this->coinOwn = 5;
	this->numOfTokenOwn = 0;
}

Player::~Player() {

}

void Player::pick_race(Races rs, PowerBudges pb) {
	this->raceOwned = rs;
	this->powerOwned = pb;

	numOfTokenOwn = raceOwned.getTokenNumber() + powerOwned.getTokenNumber();

	cout << "You pick the race " << raceOwned.getRaceName()
		<< " with special power " << powerOwned.getPowerName()
		<< " owns " << numOfTokenOwn << " coins at be." << endl;
}


void Player::conquers() {
	
	numOfTokenOwn = raceOwned.getTokenNumber() + powerOwned.getTokenNumber();

	cout << "Which place you want to pick?" << endl;
	cin >> pickRegion;

//================================

	int c = 10;
	if (c >= numOfTokenOwn) {
		cout << "You owns this region." <<endl;
	}
	else if (c < numOfTokenOwn) {
		cout << "You can't own this region." << endl;
	}
}

void Player::score(int coinPast) {
	
}



Races Player::getRaces() {
	return raceOwned;
}

PowerBudges Player::getPower() {
	return powerOwned;
}
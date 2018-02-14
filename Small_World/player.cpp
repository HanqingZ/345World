#include <iostream>
#include <string>

#include "Player.h"
//#include "Races.h"
//#include "PowerBudges.h"
//#include "MapLoader.h"

using namespace std;

Player::Player() {

}

Player::Player(int userId, string userName) {
	this->playerName = userName;
	this->id = userId;
}

Player::~Player() {

}

int Player::pick_race(Races rs, PowerBudges pb) {
	Races race = rs;
	PowerBudges specialPower= pb;
	return numOfRaceOwn;
}

//input 
bool Player::conquers(int numOfRaceOwn) {
	int c;
	cout << "Which place you want to pick?" << endl;
	cin >> c;

	if (c >= numOfRaceOwn) {
		cout << "You owns this region." <<endl;
		return true;
	}
	else if (c < numOfRaceOwn) {
		cout << "You can't own this region." << endl;
		return false;
	}
	return false;
}

int Player::score(int coinPast) {

	return coinOwn;
}


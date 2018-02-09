#include <iostream>
#include <string>

#include "Player.h"

using namespace std;

Player::Player() {

}

Player::Player(int userId, string userName) {
	this->playerName = userName;
	this->id = userId;
}

void Player::pick_race() {

}

int Player::score(int coinPast) {

	return coinOwn;
}

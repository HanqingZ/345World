#include <iostream>
#include <string>

#include "Map.h"
#include "Player.h"
#include "GameDrive.h"

using namespace std;

void main() {

	int numOfPlayer;
	int numOfTurn = 1;

	//import the map here and print in
	
	cout << "How many player do you have?" << endl;
	cin >> numOfPlayer;

	

	for (numOfTurn = 2; numOfTurn <= 10; numOfTurn++) {
		for (int i = 0; i < numOfPlayer; numOfPlayer++) {
			Player::Player();
		}
	}

}
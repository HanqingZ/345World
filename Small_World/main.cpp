#include <iostream>
#include <string>

#include "GameDrive.h"
#include "Map.h"

using namespace std;

int main() {

	int c;
	//import the map here and print in
	
/*		cout << "How many player do you have?" << endl;
		cin >> numOfPlayer;

	

		for (numOfTurn = 2; numOfTurn <= 10; numOfTurn++) {
			for (int i = 0; i < numOfPlayer; numOfPlayer++) {
				Player::Player();
			}
		}
*/
	GameDrive game;
	game.setUp();
	game.start();
	
	cin >> c;

	return 0;
}

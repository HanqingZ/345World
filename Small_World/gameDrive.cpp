#include "GameDrive.h"
#include "Map.h"
#include "Player.h"
#include <iostream>

using namespace std;

GameDrive::GameDrive() {

}

GameDrive::~GameDrive() {

}

void GameDrive::start() {
	do {
		cout << "How many people play this game? (2 to 5)" << endl;
		cin >> numOfPlayer;
	} while (numOfPlayer > 5 || numOfPlayer < 2);

	Player player = new Player*[numOfPlayer];


}

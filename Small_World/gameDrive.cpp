#include "GameDrive.h"
#include "MapLoader.h"
#include "Player.h"
#include "Races.h"
#include "PowerBudges.h"
#include <iostream>
#include <string>

using namespace std;



GameDrive::GameDrive() {

}

GameDrive::~GameDrive() {

}

void GameDrive::start() {
	numOfTurn = 0;

	//Races::setRaceType(race_type);

	do {
		cout << "How many people play this game? (2 to 5)" << endl;
		cin >> numOfPlayer;
	} while (numOfPlayer > 5 || numOfPlayer < 2);

	for(int j = 0; j < numOfPlayer; j++){
		Player player(j+1, "user");
	}

	cout << "Now is Turn #" << numOfTurn <<endl;
	//print the combo of race and special power
	charaCombo();

	for(int i = 0; i < numOfPlayer; i++){
		cout << "Player #" << i + 1 << endl;
		cout << "Please pick a Race and Special Power combo (1 to 6)" << endl;
		cin >> numOfCombo;
	}
	
	
}


void GameDrive::charaCombo() {

/*	enum RaceType {
		AMAZON, DWARVE, ELVE, GHOUL, GIANT, HALFLING,
		HUMAN, ORCS, RATMAN, SKELETON, SORCERER, TRITON,
		TROLL, WIZARD
	};
*/
	if (numOfTurn == 0) {
		for (int i = 0; i < 6; i++) {
			int k = rand() % 14;
			string& race = Races::getRaceType(k);

			int j = rand() % 2;
//			string power = PowerBudges::Powers(rand() % 20);
			
			
			cout << i+1 << ".   " << race << " "  << endl;
		}
	}
	else if (numOfTurn >= 1 && numOfTurn <= 9) {
//		Races::RaceType race = Races::RaceType(rand() % 14);
		PowerBudges::Powers power = PowerBudges::Powers(rand() % 20);
//		combo[5] = (race + power);
		for (int j = 0; j < 6; j++) {
//			cout << race << " " << power << endl;
		}
	}

}

void GameDrive::setPersonalCombo(int number) {
	combo[number];
}

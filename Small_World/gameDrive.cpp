#include "GameDrive.h"
#include "MapLoader.h"
#include "Player.h"
#include "Races.h"
#include "PowerBudges.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;


vector<int> rv;
vector<int> pv;

GameDrive::GameDrive() {
	
}

GameDrive::~GameDrive() {

}

void GameDrive::setUp() {

	numOfTurn = 0;
	int np = 0;
	playerNumCheck = false;

	//insert the number of players of this game
	cout << "How many people play this game? (2 to 5)" << endl;
	while (!playerNumCheck) {
		try {
			cin >> np;
			if (numOfPlayer < 6 || numOfPlayer >1) {
				numOfPlayer = np;
				playerNumCheck = true;
			}
			else {
				throw "Please take a number between 2 to 5.";
			}
		}
		catch (exception e) {
			cout << "How many people play this game? (2 to 5)" << endl;
		}
	}

	chooseMap(numOfPlayer);

	//create number of user at beginning
	player = new Player*[numOfPlayer];



	//print the combo of race and special power
	//and let players pick one combo
	for (int i = 0; i < numOfPlayer; i++) {
		charaCombo();

		player[i] = new Player(i + 1);

		cout << "Player #" << i + 1 << endl;
		cout << "Please pick a Race and Special Power combo (1 to 6)" << endl;
		cin >> numOfCombo;

		string sl = shufflePickRace(rv[numOfCombo - 1]);
		string s2 = shufflePickPower(pv[numOfCombo - 1]);

		//set player's race and special power
		player[i]->pick_race(r, pb);
		rv.erase(rv.begin() + numOfCombo - 1);
		pv.erase(pv.begin() + numOfCombo - 1);

	}
}

//start the game
void GameDrive::start() {

	for (numOfCombo = 1; numOfCombo <= 10; numOfCombo++) {
		cout << "Now is Turn #" << numOfTurn <<endl;
		//Print the map

		for (int j = 0; j < numOfPlayer; j++) {

			if (player[j]->getRaces().getActiveCondition() == false) {

				charaCombo();
				cout << "Please pick a Race and Special Power combo (1 to 6)" << endl;
				cin >> numOfCombo;
				
				string sl = shufflePickRace(rv[numOfCombo - 1]);
				string s2 = shufflePickPower(pv[numOfCombo - 1]);

				//set player's race and special power
				player[j]->pick_race(r, pb);
				rv.erase(rv.begin() + numOfCombo - 1);
				pv.erase(pv.begin() + numOfCombo - 1);
			}

			player[j]->conquers();

		}
	}

	//for test the Dice class Part 3
	Dice d;
	d.rollingResult(true);

}

//read corresponding map
void GameDrive::chooseMap(int nOfPly) {
	switch (nOfPly){
	case 2:
		testMap.mapReader("Map2.map");
		break;
	case 3:
		testMap.mapReader("Map3.map");
		break;
	case 4:
		testMap.mapReader("Map4.map");
		break;
	case 5:
		testMap.mapReader("Map5.map");
		break;
	default:
		break;
	}
}

int myrandom(int i) { 
		return std::rand() % i; }

//shuffle the race banners and special power badges
void GameDrive::charaCombo() {

	srand((unsigned)time(0));
	if (numOfTurn == 0) {
		for (int i = 0; i < 14; ++i) {
			rv.push_back(i);
		}
		random_shuffle(rv.begin(), rv.end(), myrandom);

		for (int j = 0; j < 20; ++j) {
			pv.push_back(j);
		}
		random_shuffle(pv.begin(), pv.end(), myrandom);
	}


	for (int j = 0; j < 6; ++j) {

		string r = shufflePickRace(rv.at(j));
		string p = shufflePickPower(pv.at(j));
		
		cout << j + 1 << ".   " << r << "\twith \t" << p  << endl;
	}

}

//index for race banners
string GameDrive::shufflePickRace(int num) {
	switch (num) {
	case 0: 
		GameDrive::setRaceType(Amazon());
		return "Amazon";
		break;
	case 1: 
		GameDrive::setRaceType(Dwarve());
		return "Dwarve";
		break;
	case 2: 
		GameDrive::setRaceType(Elve());
		return "Elve";
		break;
	case 3: 
		GameDrive::setRaceType(Ghoul());
		return "Ghoul";
		break;
	case 4: 
		GameDrive::setRaceType(Giant());
		return "Giant"; 
		break;
	case 5: 
		GameDrive::setRaceType(Halfling());
		return "Halfling";
		break;
	case 6: 
		GameDrive::setRaceType(Human());
		return "Human";
		break;
	case 7: 
		GameDrive::setRaceType(Orcs());
		return "Orcs";
		break;
	case 8:
		GameDrive::setRaceType(Ratman());
		return "Ratman";
		break;
	case 9:
		GameDrive::setRaceType(Skeleton());
		return "Skeleton";
		break;
	case 10:
		GameDrive::setRaceType(Sorcerer());
		return "Sorcerer";
		break;
	case 11:
		GameDrive::setRaceType(Triton());
		return "Triton";
		break;
	case 12:
		GameDrive::setRaceType(Troll());
		return "Troll";
		break;
	case 13:
		GameDrive::setRaceType(Wizard());
		return "Wizard";
		break;
	default:
		return "null";
		break;
	}
}

//index for special power badges
string GameDrive::shufflePickPower(int num) {

	switch (num) {
	case 0:
		GameDrive::setPowerType(Alchemist());
		return "Alchemist";
		break;
	case 1:
		GameDrive::setPowerType(Berserk());
		return "Berserk";
		break;
	case 2: 
		GameDrive::setPowerType(Bivouacking());
		return "Bivouacking";
		break;
	case 3: 
		GameDrive::setPowerType(Commando());
		return "Commando";
		break;
	case 4: 
		GameDrive::setPowerType(Diplomat());
		return "Diplomat"; 
		break;
	case 5: 
		GameDrive::setPowerType(DragonMaster());
		return "DragonMaster"; 
		break;
	case 6: 
		GameDrive::setPowerType(Flying());
		return "Flying"; 
		break;
	case 7: 
		GameDrive::setPowerType(Forest());
		return "Forest"; 
		break;
	case 8: 
		GameDrive::setPowerType(Fortified());
		return "Fortified"; 
		break;
	case 9: 
		GameDrive::setPowerType(Heroic());
		return "Heroic"; 
		break;
	case 10: 
		GameDrive::setPowerType(Hill());
		return "Hill"; 
		break;
	case 11: 
		GameDrive::setPowerType(Merchant());
		return "Merchant"; 
		break;
	case 12: 
		GameDrive::setPowerType(Mounted());
		return "Mounted"; 
		break;
	case 13: 
		GameDrive::setPowerType(Pillaging());
		return "Pillaging"; 
		break;
	case 14: 
		GameDrive::setPowerType(Seafaring());
		return "Seafaring"; 
		break;
	case 15: 
		GameDrive::setPowerType(Spirit());
		return "Spirit"; 
		break;
	case 16: 
		GameDrive::setPowerType(Stout());
		return "Stout"; 
		break;
	case 17: 
		GameDrive::setPowerType(Swamp());
		return "Swamp"; 
		break;
	case 18: 
		GameDrive::setPowerType(Underworld());
		return "Underworld"; 
		break;
	case 19: 
		GameDrive::setPowerType(Wealthy());
		return "Wealthy"; 
		break;
	default:
		return "null";
		break;
	}
}

void GameDrive::setRaceType(Races rcs) {
	this->r = rcs;
}

void GameDrive::setPowerType(PowerBudges pbs) {
	this->pb = pbs;
}
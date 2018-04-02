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

void GameDrive::start() {

	//Insert the number of players of this game
	cout << "How many people play this game? (2 to 5)" << endl;
	while (true) {
		cin >> numOfPlayer;
		if (numOfPlayer <= 5 && numOfPlayer >= 2)
			break;
		cout << "Please enter a number between 2 and 5.\n" 
			<< "How many people play this game? (2 to 5)\n";
	}
	
	while (true) {
		cout << "Which map you want to choose?(2 to 5)\n";
		cin >> numOfmap;
		if (numOfmap <= 5 && numOfmap >= 2 && numOfmap >= numOfPlayer)
			break;
		cout << "Please enter a number between 2 and 5.\n";
	}

	/*
	** 	Load the selected map based on number of players
	** 	All information about the maps has been printed
	**	If the selected map is not a graph, system stop
	*/
	chooseMapType(this->numOfmap);
	while (!testMap.checkIfIsMap()) {
		exit(0);
	}

	/*
	**	race and power card are shaffled and
	**	the number of player are created
	*/ 
	charaCombo();
	numOfTurn++;
	for (int i = 0; i < numOfPlayer; ++i) {
		ply = Player(i + 1);
		players.push_back(ply);
	}
	if (numOfmap > numOfPlayer) {
		for (int j = numOfPlayer; j < numOfmap; ++j) {
			plyAI = AI(j + 1);
			ai.push_back(plyAI);
		}
	}

	//====================================================================================
	//The game start!
	for (numOfTurn = 1; numOfTurn < 11; numOfTurn++) {
		cout << "Now is Turn #" << numOfTurn << endl;
		for (auto j : players) {
			string ans;
			cout << "Player #" << j.getPlayerId() << endl;

			if (numOfTurn == 1) {
				charaCombo();
				cout << "Please pick a Race and Special Power combo (1 to 6)" << endl;
				cin >> numOfCombo;

				string sl = shufflePickRace(rv[numOfCombo - 1]);
				string s2 = shufflePickPower(pv[numOfCombo - 1]);

				j.pick_race(r, pb, players);
				rv.erase(rv.begin() + numOfCombo - 1);
				pv.erase(pv.begin() + numOfCombo - 1);

				j.minusCoins(numOfCombo - 1);
			}
			else {
				cout << "Do u want to pick a race and special power combo? (y or n)\n";
				cin >> ans;
				if (ans == "y") {
					charaCombo();
					cout << "Please pick a Race and Special Power combo (1 to 6)" << endl;
					cin >> numOfCombo;

					string sl = shufflePickRace(rv[numOfCombo - 1]);
					string s2 = shufflePickPower(pv[numOfCombo - 1]);

					j.pick_race(r, pb, players);
					rv.erase(rv.begin() + numOfCombo - 1);
					pv.erase(pv.begin() + numOfCombo - 1);

					j.minusCoins(numOfCombo - 1);
				}
			}
			j.conquers(testMap, numOfTurn, players);
			j.redployment(testMap, players);
			j.score(testMap, players);
			for (auto a : ai) {
				AI* c = &a;
				a.strat->execute(testMap, c);
			}
		}
	}
	cout << "Thank you for enjoy this game.\n";
}

//	Choose a map depends on number of player
void GameDrive::chooseMapType(int numOfPlayer) {
	
	switch (numOfPlayer)
	{
	case 2:
		this->testMap.mapReader("Map2.map");
		//testMap.printAsImage();
		break;
	case 3:
		this->testMap.mapReader("Map3.map");
		//testMap.printAsImage();
		break;
	case 4:
		this->testMap.mapReader("Map4.map");
		//testMap.printAsImage();
		break;
	case 5:
		this->testMap.mapReader("Map5.map");
		//testMap.printAsImage();
		break;
	case 10:
		this->testMap.mapReader("failedMap.map");
		break;
	default:
		this->testMap.mapReader("testing.map");
		break;
	}
}


int myrandom(int i) {
	return std::rand() % i;
}

/*
** 	Shuffling all the Race banners and Special Power badges
** 	At the beginning of the game
** 	For the rest of the turn, just print the combo
*/
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
	else {
		for (int j = 0; j < 6; ++j) {

			string r = shufflePickRace(rv.at(j));
			string p = shufflePickPower(pv.at(j));

			cout << j + 1 << ".    " << r << " with " << p << endl;
		}
	}
}

//Index for race banners
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

// Index for special power badges
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


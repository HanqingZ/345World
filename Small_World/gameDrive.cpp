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

	numOfTurn = 0;
	int np = 0;
	playerNumCheck = false;

/*
** 	Part 1 Insert the number of players of this game
*/
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
		catch(exception e){
			cout << "How many people play this game? (2 to 5)" << endl;
		}
	}

	/*
	** 	Part 1 Load the selected map based on number of players
	** 	Part 2 All information about the maps has been printed
	**	If the selected map is not a graph, system stop
	*/
	chooseMapType(this->numOfPlayer);
	while (!testMap.checkIfIsMap()) {
		exit(1);
	}


	cout << "Now is Turn #" << numOfTurn <<endl;

	/*
	** 	When turn is 0, the race and special power has been shuffled
	** 	Print the combo of race and special power
	*/
	charaCombo();

	numOfTurn++;

	/*
	** 	Part 1.2 The right number of players is created
	** 	Part 3.1 and Part 4 Pick a Race and Special Power Combo
	** 	At the beginning of the game, the number of players has been
	** 	created and they allow to pick one combo from the six visible
	** 	combos.
	*/
	for(int i = 0; i < numOfPlayer; ++i){
		ply = Player(i + 1);

		cout << "Player #" << i + 1 << endl;
		cout << "Please pick a Race and Special Power combo (1 to 6)" << endl;
		cin >> numOfCombo;

		string sl = shufflePickRace(rv[numOfCombo - 1]);
		string s2 = shufflePickPower(pv[numOfCombo - 1]);
		
		ply.pick_race(r, pb);
		rv.erase(rv.begin() + numOfCombo - 1);
		pv.erase(pv.begin() + numOfCombo - 1);

		ply.minusCoins(numOfCombo - 1);
		cout << "You owns " << ply.getCoins() <<" coins.\n";

		ply.players.push_back(ply);

		charaCombo();
	}



	// Part 7 Following turns
	for (numOfTurn = 1; numOfTurn < 11; numOfTurn++) {
		cout << "Now is Turn #" << numOfTurn << endl;
		/*
		** 	Part 3.2 and Part 5 Conquers some regions and Redeployment
		**	Part 3.3 and Part 6 Scoring victory coins
		**	Details are in Player.h and Player.cpp
		*/
		for (int j = 0; j < numOfPlayer; ++j) {
			ply.players[j].conquers(testMap, numOfTurn);
			ply.players[j].redployment(testMap);
			ply.players[j].score(testMap);
		}
	}

	/*
	int winnerId = ply.players[0].getPlayerId();
	for (int j = 1; j < numOfPlayer; ++j) {		
		if (ply.players[j-1].getCoins() <= ply.players[j].getCoins()) {
			winnerId = ply.players[j + 1].getPlayerId();
		}
	}
	*/

	cout << "Thank you for enjoy this game.\n";
}

/*
**	Part 1.1 Choose a map depends on number of player
*/
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
** 	Part 2.2 and 2.3 
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


	for (int j = 0; j < 6; ++j) {

		string r = shufflePickRace(rv.at(j));
		string p = shufflePickPower(pv.at(j));
		
		cout << j + 1 << ".   " << r << " with " << p  << endl;
	}

}

/*
** 	Part 2.2 Index for race banners
*/
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

/*
** 	Part 2.3 Index for special power badges
*/
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


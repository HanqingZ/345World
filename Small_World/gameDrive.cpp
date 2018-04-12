#include "GameDrive.h"
#include "MapLoader.h"
#include "Player.h"
#include "Races.h"
#include "PowerBudges.h"
#include "TokenObserverDecorator.h"
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
	this->players.clear();
}

GameDrive::~GameDrive() {

}

void GameDrive::start() {

	//Insert the number of players of this game
	while (true) {
		try {
			cout << "How many people play this game? (2 to 5) \n";
			cin >> numOfPlayer;
			if (numOfPlayer > 5 || numOfPlayer < 2)
				throw numOfPlayer;
			else
				break;
		}
		catch (int x) {
			cout << "Please enter a number between 2 and 5.\n";
		}
	}
	
	//Insert the Map number for this game
	/*while (true) {
		try {
			cout << "Which map you want to choose?(2 to 5)\n";
			cin >> numOfmap;
			if (numOfmap > 5 || numOfmap < 2 || numOfmap < numOfPlayer)
				throw 0;
			else
				break;
		}
		catch (int x) {
			cout << "Please enter a number between 2 and 5.\n";
		}
	}*/

	/*
	** 	Load the selected map based on number of players
	** 	All information about the maps has been printed
	**	If the selected map is not a graph, system stop
	*/
	chooseMapType(this->numOfPlayer);
	try {
		if (!testMap.checkIfIsMap())
			throw false;
	}
	catch(bool x){
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
	/*if (numOfmap > numOfPlayer) {
		for (int j = numOfPlayer; j < numOfmap; ++j) {
			plyAI = AI(j + 1);
			players.push_back(plyAI);
		}
	}*/

	//====================================================================================
	//The game start!
	int answer =1;
	string ans, anss;

	for (numOfTurn = 1; numOfTurn < 11; numOfTurn++) {
	//for (numOfTurn = 1; numOfTurn < 5; numOfTurn++) {
		cout << endl;
		cout << "Now is Turn #" << numOfTurn << endl;
		//Add decorator
		if (answer == 1) {
			cout << "Do you want to Observer more information (0 for no and 1 for yes)?" << endl;
			cin >> answer;
			if (answer == 1) {
				addObserver(players);
				
			}
		}

		for (auto j : players) {
			//start loop for every players
			//if (!j.getIsComputer()) {
			if (j.getStrategyName() == "Aggressive") {
				strat = new Aggressive();
			}
			else if (j.getStrategyName() == "Defensive") {
				strat = new Defensive();
			}
			else if (j.getStrategyName() == "Moderate") {
				strat = new Moderate();
			}
			else if (j.getStrategyName() == "Random") {
				strat = new Random();
			}

			Player *plys = &j;
			po = new PhaseObserver();
			so = new StatisticsObserver();
			j.Attach(po);
			j.Attach(so);
			if (tokenOanwser == 1)
				j.Attach(tokenObserverDecorator);
			if (victoryCoinOAnwser == 1)
				j.Attach(victoryCoinObserver);
			j.setPlayerTurn(numOfTurn);
			string ans, anss;

			cout << "Player #" << j.getPlayerId() << endl;
			
			//	ii) for the first turn
			if (numOfTurn == 1) {
				j.setStep("pick");			//Observer
				j.Notify(plys);				//Observer
				
				charaCombo();
				cin >> numOfCombo;
				string sl = shufflePickRace(rv[numOfCombo - 1]);
				string s2 = shufflePickPower(pv[numOfCombo - 1]);

				strat->pickRace(r, pb, plys);
				rv.erase(rv.begin() + numOfCombo - 1);
				pv.erase(pv.begin() + numOfCombo - 1);
				j.minusCoins(numOfCombo - 1);

				strat->execute(testMap, plys, players, numOfTurn);

				j.setStep("conquer");		//Observer
				j.Notify(plys);				//Observer
				strat->conquers(testMap, plys, players, tokenOanwser);
				j.setStep("reDeploy");		//Observer
				j.Notify(plys);				//Observer
				strat->redeployment(testMap, plys, players);
				j.setStep("score");			//Observer
				j.Notify(plys);				//Observer
				strat->score(testMap, plys, players, victoryCoinOAnwser);
				j.Detach(po);				//Observer
				j.Detach(so);				//Observer
			}
			//	iii) for the rest turns
			else {
				if(j.getNumberOfDecline() == 1){
					charaCombo();
					cin >> numOfCombo;
					string sl = shufflePickRace(rv[numOfCombo - 1]);
					string s2 = shufflePickPower(pv[numOfCombo - 1]);

					j.setStep("pick");		//Observer
					j.Notify(plys);				//Observer
					strat->pickRace(r, pb, plys);
					rv.erase(rv.begin() + numOfCombo - 1);
					pv.erase(pv.begin() + numOfCombo - 1);
					j.minusCoins(numOfCombo - 1);

					strat->execute(testMap, plys, players, numOfTurn);

					j.setStep("conquer");		//Observer
					j.Notify(plys);				//Observer
					strat->conquers(testMap, plys, players, tokenOanwser);
					j.setStep("reDeploy");		//Observer
					j.Notify(plys);				//Observer
					strat->redeployment(testMap, plys, players);
					j.setStep("score");			//Observer
					j.Notify(plys);				//Observer
					strat->score(testMap, plys, players, victoryCoinOAnwser);
					j.Detach(po);				//Observer
					j.Detach(so);				//Observer
				}
				else {
					cout << "Do u want to decline your current combo? (y or n)\n";
					cin >> anss;
					if (anss == "y" && j.getNumberOfDecline() == 0 
						&& (j.getStrategyName() == "Moderate" || j.getStrategyName() == "Random")) {
						strat->chooseDecline(testMap, plys, players);
					}
					else {
						strat->execute(testMap, plys, players, numOfTurn);
						j.setStep("conquer");		//Observer
						j.Notify(plys);				//Observer
						strat->conquers(testMap, plys, players, tokenOanwser);
						j.setStep("reDeploy");		//Observer
						j.Notify(plys);				//Observer
						strat->redeployment(testMap, plys, players);
					}

					j.setStep("score");			//Observer
					j.Notify(plys);				//Observer
					strat->score(testMap, plys, players, victoryCoinOAnwser);
					j.Detach(po);				//Observer
					j.Detach(so);				//Observer
				}
			}			
			//}

			//AI loop start
			/*else {
				if (j.race.empty() || !j.race[0].getActiveCondition()) {
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

				Player* ai = &j;

				if (j.getStrategyName() == "Aggressive") {
					strat = new Aggressive();
					strat->execute(testMap, ai, players, numOfTurn);
				}
				else if (j.getStrategyName() == "Defensive") {
					strat = new Defensive();
					strat->execute(testMap, ai, players, numOfTurn);
				}
				else if (j.getStrategyName() == "Moderate") {
					strat = new Moderate();
					strat->execute(testMap, ai, players, numOfTurn);
				}
				else {
					strat = new Random();
					strat->execute(testMap, ai, players, numOfTurn);
				}

			}*/
			//AI loop end
		}

		if (answer == 1) {
			//delete observers after each turn 
			deleteObservers();
		}

	}

	//	iv) reveal the winner at the end
	int a = 0;
	int c;
	for (auto p : players) {
		if (p.getCoins() > a) {
			a = p.getCoins();
			c = p.getPlayerId();
		}
	}
	cout << "The winner of this game is Player #" << c << endl;

	cout << "Thank you for enjoy this game.\n";
}

//Choose a map depends on number of player
void GameDrive::chooseMapType(int numOfPlayer) {
	
	switch (numOfPlayer)
	{
	case 2:
		this->testMap.mapReader("Map2.map");
		break;
	case 3:
		this->testMap.mapReader("Map3.map");
		break;
	case 4:
		this->testMap.mapReader("Map4.map");
		break;
	case 5:
		this->testMap.mapReader("Map5.map");
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

void GameDrive::addVictoryCoinObserver(int victoryCoinOAnwser, vector<Player> players) {
	victoryCoinObserver = new VictoryCoinObserverDecorator(PhaseObserver());
	for (auto p : players) {
		p.Attach(victoryCoinObserver);
	}
}

void GameDrive::addTokenObserverDecorator(int tokenOanwser, vector<Player> players) {
	tokenObserverDecorator = new TokenObserverDecorator(PhaseObserver());
	for (auto p : players) {
		p.Attach(tokenObserverDecorator);
	}
}

void GameDrive::deleteObservers() {

	for (auto p : players) {
		p.Detach(tokenObserverDecorator);
		p.Detach(victoryCoinObserver);
	}
	tokenOanwser = 0;
	victoryCoinOAnwser = 0;
}

void GameDrive::addObserver(vector<Player> players) {
	cout << "Do you want to observe your token status (o for no and 1 for yes)?" << endl;
	//int tokenOanwser;
	cin >> tokenOanwser;
	if (tokenOanwser == 1) {
		addTokenObserverDecorator(tokenOanwser, players);
	}
	cout << "Do you want to observe your coins status (o for no and 1 for yes)?" << endl;
	//int victoryCoinOAnwser;
	cin >> victoryCoinOAnwser;
	if (victoryCoinOAnwser == 1) {
		addVictoryCoinObserver(tokenOanwser, players);
	}
}
#include "Dice.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

//using namespace std;

Dice::Dice() {
//	rolldice = 0;
}

Dice::~Dice() {

}

//Rolling the special dice and get the result
int Dice::rollingResult(bool turnStatus) {
	vector<int> rolls;

	srand((unsigned)time(0));
	rolldice = rand() % 6;

	if (rolldice >= 4 || rolldice == 0) {
		rolls.push_back(0);
		cout << "Rolling result is 0" << endl;
		return 0;
	}
	else {
		rolls.push_back(rolldice);
		cout << "Rolling result is " << rolldice << endl;
		return rolldice;
	}

}

/*
//Compare and get the selected region
int Dice::getRollintResult(int a) {
	cout << "How many races you want to place?" << endl;
	cin >> placedRace;

	int i = rollingResult(true);

	if ((placedRace + )) {

	}
	else {
	
	}
}
*/
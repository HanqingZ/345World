#include "Dice.h"
#include <iostream>
#include <vector>

//using namespace std;

Dice::Dice() {

}

Dice::~Dice() {

}

//Rolling the special dice and get the result
int Dice::rollingResult(bool turnStatus) {
	vector<int> rolls;

	rolldice = rand() % 6;

	if (rolldice > 4 && rolldice == 0) {
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
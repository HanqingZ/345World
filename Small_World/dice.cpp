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
int Dice::rollingResult() {

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

int Dice::getRollintPercent(int a)
{
	int sum = 0;
	for (size_t i = 0; i < rolls.size(); i++) {
		if (rolls[i] == a) {
			sum++;
		}
	}
	return sum/rolls.size();
}
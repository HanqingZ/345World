#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <vector>

using namespace std;

class Dice {
private:
	int rolldice;
	int placedRace;
public:
	Dice();
	~Dice();
	int rollingResult();
	int getRollintPercent(int);

	vector<int> rolls;
};

#endif
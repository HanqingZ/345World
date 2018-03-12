#ifndef DICE_H
#define DICE_H

#include <iostream>

using namespace std;

class Dice {
private:
	int rolldice;
	int placedRace;
public:
	Dice();
	~Dice();
	int rollingResult(bool);
//	int getRollintResult(int);
};

#endif
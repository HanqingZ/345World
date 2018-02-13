#ifndef DICE_H
#define DICE_H

#include <iostream>

using namespace std;

class Dice {
	int rolldice;
public:
	Dice();
	~Dice();
	int rollingResult(bool);
};

#endif
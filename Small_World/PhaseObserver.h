#ifndef PHASEOBSERVER_H
#define PHASEOBSERVER_H

#include "Decorator.h"
#include "Player.h"
using namespace std;

//class Player;

class PhaseObserver : public Observer
{
public:
	PhaseObserver();
	virtual void Update(Player*);
	//virtual void Update(int playerId);
};

#endif
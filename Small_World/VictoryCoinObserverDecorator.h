#pragma once

#include "ObserverDecorator.h"
#include "Player.h"
using namespace std;
class VictoryCoinObserverDecorator :public ObserverDecorator {
	public:
	VictoryCoinObserverDecorator(Observer decoratedObserver) :ObserverDecorator(decoratedObserver) {}
	virtual void Update(Player* p);
};
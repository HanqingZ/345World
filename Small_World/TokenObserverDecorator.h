#pragma once

#include "ObserverDecorator.h"
#include "Player.h"
using namespace std;
class TokenObserverDecorator :public ObserverDecorator {
	public:
	TokenObserverDecorator(Observer decoratedObserver):ObserverDecorator(decoratedObserver) {}
	virtual void Update(Player* p);
};
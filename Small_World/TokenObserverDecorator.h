#pragma once

#include "ObserverDecorator.h"
#include "Player.h"
using namespace std;
class TokenObserverDecorator :public ObserverDecorator {
	public:
		TokenObserverDecorator(Observer decoratedObserver) :ObserverDecorator(decoratedObserver)  {}
		/*{
			observerType = "token observer";
		}*/
	virtual void Update(Player* p);
	
};

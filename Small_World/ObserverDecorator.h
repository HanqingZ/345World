#ifndef OBSERVERDECORATOR_H
#define OBSERVERDECORATOR_H

//#include "Decorator.h"
#include "Observer.h"
using namespace std;

class ObserverDecorator : public Observer
{
protected:
	Observer decoratedObserver;
public:

	ObserverDecorator(Observer decoratedObserver) {
		this->decoratedObserver = decoratedObserver;
	}
	//virtual void Update(Subject* s) = 0;
	virtual void Update(Player* p) = 0;
	virtual void Update(int numRegion, Player * p) = 0;
};

#endif
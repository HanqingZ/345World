#ifndef OBSERVERDECORATOR_H
#define OBSERVERDECORATOR_H

#include "Decorator.h"

using namespace std;

class ObserverDecorator : public Decorator
{
protected:
	Decorator* decoStat;
public:
	ObserverDecorator(Decorator* decoStat) { this->decoStat = decoStat; };		//Constructor
	void Update(Subject* s) { decoStat->Update(s); };
	void Update(Player* p) { decoStat->Update(p); };
};

#endif
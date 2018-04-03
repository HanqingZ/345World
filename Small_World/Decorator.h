#ifndef DECORATOR_H
#define DECORATOR_H

#include "Observer.h"

using namespace std;

class Decorator : public Observer
{
public:
	Decorator() {};		 
	virtual void Update(Subject* s) = 0;	 
	virtual void Update(Player* p) = 0;	 
};

#endif
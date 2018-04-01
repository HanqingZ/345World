#ifndef BASICOBSERVER_H
#define BASICOBSERVER_H

#include "Decorator.h"

using namespace std;

class Player;

class BasicObserver : public Decorator
{
public:
	BasicObserver();
	virtual void Update(Subject*);
	virtual void Update(Player*);
};

#endif
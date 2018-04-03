#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
#include <iostream>
using namespace std;

class Subject;
class Player;

class Observer
{
public:
	string observerType;

	//Observer();			 
	//virtual void Update() = 0;	 
	virtual void Update(Player*) {};
	//virtual void Update(MapLoader*) = 0;
	virtual void Update(int numRegion, Player * p) {};
};

#endif
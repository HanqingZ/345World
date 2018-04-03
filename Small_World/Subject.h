#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
#include <vector>
#include "Observer.h"
//#include "Player.h"
using namespace std;

class Subject
{
protected:
	vector<Observer*> observers;	//List of observers attached to the object.

public:
	Subject();
	~Subject();
	virtual void Attach(Observer*);		//Attaches an observer to an observable object.	
	virtual void Detach(Observer*);		//Detaches an observer from an observable object.	
	virtual void Notify();				 
	//virtual void Notify(Subject*);		 
	virtual void Notify(Player*);
};

#endif
#include "Subject.h"
#include <iostream>
#include <string>


Subject::Subject()
{

}

Subject::~Subject()
{

}

void Subject::Attach(Observer* o)
{
	observers.push_back(o);

	//cout << s->type << " Subscribed" << endl;
}

void Subject::Detach(Observer* o)
{
	for (int i = 0; i < int(observers.size()); i++)
	{
		if (observers[i] == o)
		{
			observers.erase(observers.begin() + i);
			break;
		}
	}

	cout << o->observerType << "Unsubscribed" << endl;
}

void Subject::Notify()
{
	//cout << "Notify" << endl;

	for (int i = 0; i < int(observers.size()); i++)
	{
		//observers[i]->Update(this);
	}
}

void Subject::Notify(Player* s)
{
	//cout << "Notify" << endl;

	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->Update(s);
	}
}
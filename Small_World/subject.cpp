#include "Subject.h"
#include <iostream>
#include <string>


Subject::Subject()
{

}

Subject::~Subject()
{

}

void Subject::Attach(Observer* s)
{
	observers.push_back(s);

	//cout << s->type << " Subscribed" << endl;
}

void Subject::Detach(Observer* s)
{
	for (int i = 0; i < int(observers.size()); i++)
	{
		if (observers[i] == s)
		{
			observers.erase(observers.begin() + i);
			break;
		}
	}

	cout << s->type << "Unsubscribed" << endl;
}

void Subject::Notify()
{
	//cout << "Notify" << endl;

	for (int i = 0; i < int(observers.size()); i++)
	{
		observers[i]->Update(this);
	}
}

void Subject::Notify(Subject* s)
{
	//cout << "Notify" << endl;

	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->Update(s);
	}
}
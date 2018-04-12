#include "Subject.h"
#include <iostream>
#include <string>


Subject::Subject()
{

}

Subject::~Subject()
{
	/*for (vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
		delete(*it);
	}
	observers.clear();*/
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

void Subject::Notify(int numRegion, Player * p)
{
	for (size_t i = 0; i < observers.size(); i++) {
		if (observers[i]->observerType == "Statistics observer") {
		//	observers[i]->Update(numRegion, p);
		}
	}
}

//void Subject::Notify(MapLoader* m )
//{
//	for (size_t i = 0; i < observers.size(); i++)
//	{
//		if (observers[i]->observerType == "Statistics observer") {
//			observers[i]->Update(m);
//		 }
//	}
//}

void Subject::Notify(Player* s)
{
	//cout << "Notify" << endl;

	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->Update(s);
		
	}
}

void Subject::NotifyAll(int numRegion, vector<Player> &players)
{
	for (size_t i = 0; i < observers.size(); i++) {
		if (observers[i]->observerType == "Statistics observer") {
			observers[i]->UpdateP(numRegion, players);
		}
	}
}
//void Subject::NotifyT(Player* s)
//{
//	//cout << "Notify" << endl;
//
//	for (size_t i = 0; i < observers.size(); i++)
//	{
//		 
//		if (observers[i]->observerType == "token observer") {
//			observers[i]->Update(s);
//		}
//	}
//}

//void Subject::NotifyC(Player* s)
//{
//	//cout << "Notify" << endl;
//
//	for (size_t i = 0; i < observers.size(); i++)
//	{
//
//		if (observers[i]->observerType == "victory observer") {
//			observers[i]->Update(s);
//		}
//	}
//}
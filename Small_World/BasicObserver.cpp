#include <iostream>
#include "BasicObserver.h"
#include "Player.h"

using namespace std;

BasicObserver::BasicObserver()
{
	observerType = "Basic";
}

void BasicObserver::Update(Player* p)
{
	cout << "Player: " << p->playerID << endl;
	cout << "Countries Controlled: " << p->GetNumCountries() << endl;
	cout << "Armies Owned: " << p->GetArmiesOwned() << endl;
	cout << "Cards in Hand: " << p->HandSize() << endl << endl << endl;
}

void BasicObserver::Update(Subject* s)
{
	cout << "You are in stats" << endl;
}
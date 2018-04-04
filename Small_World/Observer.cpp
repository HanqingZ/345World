#include <iostream>

#include "Observer.h"

using namespace std;

Observer::Observer()
{
	observerType = "Observer";
}

void Observer::Update(Subject* s)
{
	cout << "Observable has changed!" << endl;
}
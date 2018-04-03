#include "StatisticsObserver.h"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
#include "Player.h"

using namespace std;
StatisticsObserver::StatisticsObserver()
{
	observerType = "Statistics observer";
}
void StatisticsObserver::Update(int numRegion, Player * p)
{
	int own = p->ownedRegionSet.size();
	double percent = (own / numRegion)*100;
	cout << "The percentage of the world cpntrolled by you is " <<percent<<"%" << endl;
}


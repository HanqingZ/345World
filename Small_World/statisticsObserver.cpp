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
//void StatisticsObserver::Update(int numRegion, Player * p)
//{
//	int own = p->ownedRegionSet.size();
//	cout << own << endl;
//	double percent = ((double)own / (double)numRegion)*100;
//	cout << numRegion << endl;
//	cout << percent << endl;
//	cout << "The percentage of the world cpntrolled by you is " <<percent<<"%" << endl;
//}

void StatisticsObserver::UpdateP(int numRegion, vector<Player> &players) {
	int playerID=0;
	int own=0;
	double percent=0.0;
	Player* pr;
	for (auto p : players) {
		 pr= &p;
		 playerID = p.getPlayerId();

		//own = (double)(pr->getPlayerRegionSize());
	//	own = (p.getPlayerRegionSize());
		own = p.getPlayerRegionSize();
	cout << pr->getPlayerRegionSize() << endl;
		percent = (own / (double)numRegion) * 100;
	//	own = (double)(pr->getPlayerRegionSize());
	//	cout << numRegion << endl;
	//	cout << percent << endl;
		cout << "The percentage of the world cpntrolled by Player "<< playerID <<" is " << percent << "%" << endl;
	}
}
#include "TokenObserverDecorator.h"
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
#include "Player.h"

using namespace std;
void TokenObserverDecorator::Update(Player* player) {
	 
	int token = player->getTokenNumber();
	int playerId = player->getPlayerId();
	cout << "Player " << playerId << " has " << token << "tokens" << endl;
}
//TokenObserverDecorator::TokenObserverDecorator(Observer decoratedObserver) :ObserverDecorator(decoratedObserver) {
//	observerType = "token observer";
//}
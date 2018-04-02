#include "Map.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


Map::Map() {
	
}

Map::~Map() {
	maps.clear();
}


//void Map::addEdges(int i) {
//	lists.push_back(i);
//}

void Map::addMapEdges(list<int> depar) {

	maps.push_back(depar);
}

list<int> Map::findEdges(int rg) {
	return maps[rg];
}

bool Map::findAdjencent(int rg, int rid) {
	i = find(maps[rg].begin(), maps[rg].end(), rid);
	if (i != maps[rg].end())
		return true;
	else
		return false;
}

void Map::printEdges(int depart) {
	cout << "Number " << depart << " links to: ";
	for (i = maps[depart].begin(); i != maps[depart].end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}
#ifndef MAP_H
#define MAP_H

//#include "MapLoader.h"
//#include "Region.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdio.h>
#include <cstdlib>

using namespace std;

struct RegionNode {
	int depar;
};

//create the realation between each region
class Map {
protected:
	list<int>::iterator i;
public:
	Map();
	~Map();

	//void addEdges(int);
	void addMapEdges(list<int>);
	list<int> findEdges(int);
	void printEdges(int);
	
	vector<list<int>> maps;
	//list<int> lists;
	
};

#endif

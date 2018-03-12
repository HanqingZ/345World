#ifndef MAP_H
#define MAP_H

#include "MapLoader.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Nodes {
private:
	//int key;
	//int size;
public:
	Nodes();
	~Nodes();
	void addLink(int);
	void printLink();

	list<int> lists;
};

//create the realation between each region
class Map {
public:
	Map();
	~Map();

	void addEdges(Nodes);
	void printEdges(int);
	
	vector<Nodes> mps;
	Nodes list2;

private:
	//vector<Region> regions; //nodes
	//int nodesCode; // index or departure of the edges 
	
};

#endif

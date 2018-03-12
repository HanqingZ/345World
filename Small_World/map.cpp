#include "Map.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Nodes::Nodes() {

}

Nodes::~Nodes() {

}

void Nodes::addLink(int v) {
	lists.push_back(v);
}

void Nodes::printLink() {
	for (auto i : lists) {
		cout << i << " ";
	}
}

//===============================================================

Map::Map() {
	
}

Map::~Map() {

}

void Map::addEdges(Nodes depar) {

	mps.push_back(depar);
}

void Map::printEdges(int depar) {
	cout << "Number " << depar << " links to:" << endl;
	mps[depar].printLink();
}
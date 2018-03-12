#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Region.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//load the .map file and set them value to other classes
class MapLoader {
private:
	int numOfRegion;
	string mapFile;
	string numOfPlayers;
	int mapWidth;
	int mapLength;

public:
	MapLoader();
	~MapLoader();

	void mapReader(string);

	void getFileRead(ifstream&);
	void getRegions(ifstream&);
	void getEdges(ifstream&);

	//Id, x, y, type of region, printed logo
	void addRegions(int, string, int, int, string);

	void addEdges(int);
	void addEdge2(int);

	void printAsImage();
	char shownLogo(string);

	vector<Region> regions;
};

#endif
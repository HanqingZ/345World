#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Region.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class MapLoader {
protected:
	int numOfRegion;
	string mapFile;
	string numOfPlayers;
	int mapWidth;
	int mapLength;

	Map maps;

public:
	MapLoader();
	~MapLoader();

	//Main methods of reading files
	void mapReader(string);
	void getFileRead(ifstream&);
	void getRegions(ifstream&);
	void getEdges(ifstream&);

	//Adjective methods
	void addRegions(int, int, int, string, string, string, string, string, string);
	bool checkIfIsMap();
	int getMapWidth();
	int getMapLength();
	void modifyRegion(int);

	void printOnlySideRegion();
	void printSurroungdingRegion(int);

	void printAsImage();
	char shownLogo(string);


	vector<Region> regions;
	list<int> lst;
};

#endif
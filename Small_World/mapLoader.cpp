#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

MapLoader::MapLoader() {
	numOfRegion = 0;
}

MapLoader::~MapLoader() {

}

/*
** 	Part 1.1 Read the selected map depends on number of players
*/
void MapLoader::mapReader(string file) {
	{
		ifstream mapFile;
		string output;

		mapFile.open(file);

		if (mapFile.is_open())
		{
			cout << "Loading Map!" << endl;

			while (!mapFile.eof())
			{
				getline(mapFile, output);

				if (output == "[Map]")
				{
					//cout << "File:" << endl;
					getFileRead(mapFile);
				}

				if (output == "[Region]")
				{
					cout << "Those are regions:" << endl;
					getRegions(mapFile);
				}
				if (output == "[Edges]")
				{
					cout << "The connections:" << endl;
					getEdges(mapFile);
				}
				
			}

			cout << "Loading Complete!" << endl;
		}
		else
			cout << "Cannot Open File!" << endl;

		mapFile.close();

	}
}

/*
** Read the [Map] part of the map file
** 	set the value of mapLength and mapWidth
*/
void MapLoader::getFileRead(ifstream& mapfile) {
	string line;
	string equal = "=";

	getline(mapfile, line);
	mapFile = line.substr(line.find(equal) + 1);
	cout << "This map called " << mapFile << endl;

	getline(mapfile, line);
	numOfPlayers = line.substr(line.find(equal) + 1);
	cout << "This Map is for " << numOfPlayers << " players" << endl;

	getline(mapfile, line);
	mapWidth = stoi(line.substr(line.find(equal) + 1));
	cout << "Width is " << mapWidth << endl;

	getline(mapfile, line);
	mapLength = stoi(line.substr(line.find(equal) + 1));
	cout << "Length is " << mapLength << endl;

}

/*
** 	Read the [Regions] part of the map file
** 	Add it to the region vector
*/
void MapLoader::getRegions(ifstream& mapfile) {

	string lines;
	string spaced = ",";
	int regionId;
	//string regionName;
	int posX;
	int posY;
	string regionType;
	string ca, lai, ma, lt, ctw;
	//string regionFunc;

	while (!mapfile.eof()) {
		while (getline(mapfile, lines) && lines != "") {
			
			
			regionId = stoi(lines.substr(0, lines.find(spaced)));
			lines = lines.substr(lines.find(spaced) + 1);

			posX = stoi(lines.substr(0, lines.find(spaced)));
			lines = lines.substr(lines.find(spaced) + 1);
			posY= stoi(lines.substr(0, lines.find(spaced)));
			lines = lines.substr(lines.find(spaced) + 1);

			regionType = lines.substr(0, lines.find(spaced));
			lines = lines.substr(lines.find(spaced) + 1);

			ca = lines.substr(0, lines.find(spaced));
			lines = lines.substr(lines.find(spaced) + 1);

			lai = lines.substr(0, lines.find(spaced));
			lines = lines.substr(lines.find(spaced) + 1);

			ma = lines.substr(0, lines.find(spaced));
			lines = lines.substr(lines.find(spaced) + 1);

			lt = lines.substr(0, lines.find(spaced));
			lines = lines.substr(lines.find(spaced) + 1);

			ctw = lines.substr(0, lines.find(spaced));
			lines = lines.substr(lines.find(spaced) + 1);


			addRegions(regionId, posX, posY, regionType, ca, lai, ma, lt, ctw);

			if (lines == ";") {
				lines = "";
			}
			
		}
		break;
	}
}

/*
** 	Read the [Edges] part of the map file
** 	Add it to the maps vector
*/
void MapLoader::getEdges(ifstream& mapfile) {

	string lines;
	string linking = ">";
	string spaced = ",";
	string stop = ".";
	int regionId;
	int dest;

	while (!mapfile.eof()) {
		while (getline(mapfile, lines) && lines != "") {
			lst.clear();
			regionId = stoi(lines.substr(0, lines.find(linking)));
			lines = lines.substr(lines.find(linking) + 1);

			while (lines != "." && lines != ";") {
				dest = stoi(lines.substr(0, lines.find(spaced)));
				lines = lines.substr(lines.find(spaced) + 1);
			
				lst.push_back(dest);
			}

			this->maps.addMapEdges(lst);

			if (lines == ";") {
				lines = "";
			}

			maps.printEdges(regionId);
		}
	}

}

//=========================================================================

/*
	Create new region object and add to regions vector
*/
void MapLoader::addRegions(int rid, int rx, int ry, string rt, 
	string ca, string lai, string ma, string lt, string ctw) {
	
	bool cavern, lairs, magic, lostTribe, closeToWater;

	if (ca == "F") {
		cavern = false;
	}
	else if (ca == "T") {
		cavern = true;
	}

	if (lai == "F") {
		lairs = false;
	}
	else if (lai == "T") {
		lairs = true;
	}

	if (ma == "F") {
		magic = false;
	}
	else if (ma == "T") {
		magic = true;
	}

	if (lt == "F") {
		lostTribe = false;
	}
	else if (lt == "T") {
		lostTribe = true;
	}

	if (ctw == "F") {
		closeToWater = false;
	}
	else if (ctw == "T") {
		closeToWater = true;
	}

	Region r = Region(rid, rx, ry, rt, cavern, lairs, magic, lostTribe, closeToWater);
	r.shown();
	regions.push_back(r);
}


/*
	Part 1.1 
	Check whether the selected map file is a connected graph
	If the selected maps is not a graph, reject it
*/
bool MapLoader::checkIfIsMap() {
	for (size_t i = 0; i < regions.size(); ++i) {
		if (maps.maps[i].empty()) {
			cout << "It's not a map." << endl;
			maps.maps.clear();
			return false;
		}
	}
	cout << "It's a map." << endl;
	return true;
}

int MapLoader::getMapWidth() {
	return this->mapWidth;
}

int MapLoader::getMapLength() {
	return this->mapLength;
}


void MapLoader::modifyRegion(int index) {
	regions.at(index).setImmuneRegion();
}

void MapLoader::printOnlySideRegion() {
	for (size_t k = 0; k < regions.size(); ++k) {
		if ((regions[k].getPositionX() == 0 
			|| regions[k].getPositionY() == 0
			|| regions[k].getPositionX() == mapLength
			|| regions[k].getPositionY() == mapWidth) 
			&& regions[k].getRegionType() != "Sea") {
			regions[k].shown();
		}
	}
}

void MapLoader::printSurroungdingRegion(int rid) {
	lst = maps.findEdges(rid);
	while(!lst.empty()) {
		int k = lst.front();
		regions[k].shown();
		lst.pop_front();
	}
	//lst.clear();
}

//=========================================================================

void MapLoader::printAsImage() {
	char maps[13][13];

	for (size_t k = 0; k < regions.size(); ++k) {
		maps[regions[k].getPositionX()][regions[k].getPositionY()]
			= shownLogo(regions[k].getRegionType());
	}

	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapLength; j++) {
			cout << " " << maps[i][j] << " ";
		}
		cout << endl;
	}
	
}

char MapLoader::shownLogo(string rt) {
	if (rt == "Mountain") {
		return 'M';
	}
	else if (rt == "Forest") {
		return 'W';
	}
	else if (rt == "Lake") {
		return 'L';
	}
	else if (rt == "Hill") {
		return 'H';
	}
	else if (rt == "Swamp") {
		return 'S';
	}
	else if (rt == "Farmland") {
		return 'F';
	}
	return '-';
}
 


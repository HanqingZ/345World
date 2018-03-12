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

void MapLoader::getFileRead(ifstream& mapfile) {
	string line;
	string equal = "=";

	getline(mapfile, line);
	mapFile = line.substr(line.find(equal) + 1);

	getline(mapfile, line);
	numOfPlayers = line.substr(line.find(equal) + 1);

	/*getline(mapfile, line);
	mapWidth = stoi(line.substr(0, line.find(equal) + 1));
	cout << "Width is " << mapWidth << endl;
	getline(mapfile, line);
	mapLength = stoi(line.substr(0, line.find(equal) + 1));
	cout << "Length is " << mapLength << endl;*/
}

void MapLoader::getRegions(ifstream& mapfile) {

	string lines;
	string spaced = ",";
	int regionId;
	string regionName;
	int posX;
	int posY;
	string regionType;
	string regionFunc;

	while (!mapfile.eof()) {
		while (getline(mapfile, lines) && lines != "") {
			
			
			regionId = stoi(lines.substr(0, lines.find(spaced)));
			lines = lines.substr(lines.find(spaced) + 1);

			regionName = lines.substr(0, lines.find(spaced));
			lines = lines.substr(lines.find(spaced) + 1);

			posX = stoi(lines.substr(0, lines.find(spaced)));
			lines = lines.substr(lines.find(spaced) + 1);
			posY= stoi(lines.substr(0, lines.find(spaced)));
			lines = lines.substr(lines.find(spaced) + 1);

			regionType = lines.substr(0, lines.find(spaced));
			lines = lines.substr(lines.find(spaced) + 1);

			//Region r = Region(regionId, regionName, posX, posY, regionType);
			//r.shown();

			addRegions(regionId, regionName, posX, posY, regionType);
			
			if (lines == ";") {
				lines = "";
			}
		}
		break;
	}
}

void MapLoader::getEdges(ifstream& mapfile) {

	string lines;
	string linking = ">";
	string spaced = ",";
	int regionId;
	int dest1;
	int dest2;
	Nodes i;
	Map mps;

	while (!mapfile.eof()) {
		while (getline(mapfile, lines) && lines != "") {
			regionId = stoi(lines.substr(0, lines.find(linking)));
			lines = lines.substr(lines.find(linking) + 1);
			//lines = lines.substr(lines.find(linking) + 1);

			dest1 = stoi(lines.substr(0, lines.find(spaced)));
			lines = lines.substr(lines.find(spaced) + 1);
				
			i.addLink(dest1);
			cout << "Region " << regionId << " is related to " << dest1 << endl;

			dest2 = stoi(lines.substr(0, lines.find(spaced)));
			lines = lines.substr(lines.find(spaced) + 1);

			i.addLink(dest2);
			cout << "Region " << regionId << " is related to " << dest2 << endl;

			if (lines == ";") {
				lines = "";
			}

			mps.addEdges(i);
		}
	}
}

//=========================================================================

void MapLoader::addRegions(int rid, string rname, int rx, int ry, string rt) {

	Region r = Region(rid, rname, rx, ry, rt);
	r.shown();
	regions.push_back(r);
}

//void MapLoader::addEdges(int dest) {
//	Nodes i;
//	i.addLink(dest);
//	
//}
//void MapLoader::addEdge2(int depart) {
//	Map mps;
//	mps.push_back()
//}

//=========================================================================

void MapLoader::printAsImage() {
	//char maps[6][9];

	//string rname;
	//int rx, ry;

	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 9; j++) {
			cout << " - ";
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
 
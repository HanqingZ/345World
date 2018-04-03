#ifndef REGION_H
#define REGION_H

#include <iostream>
#include <string>
#include <vector>

//#include "Player.h"

using namespace std;

class Region {
	/*enum RegionType {
	Montain, Forest, Lake,
	Hill, Swamp, Farmland
	};
	enum RegionFunc {
	Lairs, Cavern, Mountain, Magic, Encampment,
	GroundHoule, Dragon, Hero, Lost Tribes, Null
	};*/
protected:
	int regionId;
	int posX;
	int posY;
	string regionType;
	int ownerID;
	int containToken;
	bool lairs;
	bool cavern;
	bool magic;
	bool lostTribes;
	bool closeToWater;
	bool containTrollLairs;
	bool containFortresses;
	bool containEncampments;
	bool immune;

public:
	Region();
	Region(int, int, int, string, bool, bool, bool, bool, bool);
	//Region(int, int);
	~Region();

	void setRegionId(int);
	//void setPositionX(int);
	//void setPositionY(int);
	//void setRetionType(string);
	//void setRegionFunc(string);
	//void setRegionOwner(Player*);
	void addContainToken(int);
	void minusContainToken(int);
	void resetContainToken(bool);
	void setImmuneRegion();
	void setOwnerID(int);
	void setIsLostTribes(bool);
	void setContainTrollLairs(bool);
	void setContainFortresses(bool);
	void setContainEncampments(bool);

	int getRegionId();
	int getPositionX();
	int getPositionY();
	string getRegionType() { return regionType; };
	int getOwnerId();
	int getContainToken();
	int getUsefulContainToken();
	bool getIsCavern();
	bool getIsLairs();
	bool getIsLostTribes();
	bool getIsMagic();
	bool getIsCloseToWater();
	bool getContainTrollLairs();
	bool getContainFortresses();
	bool getContainEncampments();
	bool getImmuneRegion();

	void shown();

	//Player* ownedByPlayer;
	
	//	string regionFunc[];
};


#endif
#ifndef REGION_H
#define REGION_H

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

using namespace std;

class Region {
protected:
	/*enum RegionType {
	Montain, Forest, Lac,
	Hill, Swamp, Farmland
	};
	enum RegionFunc {
	Lairs, Cavern, Mountain, Magic, Encampment,
	GroundHoule, Dragon, Hero, Lost Tribes, Null
	};*/
protected:
	int regionId;
	string regionName;
	int posX;
	int posY;
	string regionType;
	bool magic;
	bool lairs;
	bool cavern;
	bool lostTribes;

	//	string shownLogo;


public:
	Region();
	Region(int, string, int, int, string
		//		, bool, bool, bool, bool
	);
	Region(int, Player, int);
	~Region();

	void setRegionId(int);
	void setRegionName(string);
	void setPositionX(int);
	void setPositionY(int);
	void setRetionType(string);
	//	void setRegionFunc(string);
	//	void setLogo(string);
	void setRegionOwner(Player);
	void setContainToken(int);

	int getRegionId();
	string getRegionName();
	int getPositionX();
	int getPositionY();
	string getRetionType() { return regionType; };
	//string getLogo();
	//Player getRegionOwner();
	int getContainToken();

	void shown();


	Player* ownedByPlayer;
	int containToken;
	//	string regionFunc[];
};


#endif
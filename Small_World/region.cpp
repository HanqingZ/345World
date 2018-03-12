#include "Region.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Region::Region() {
	this->regionId = 0;
	this->regionName = "";
	this->posX = 0;
	this->posY = 0;
	this->regionType = nullptr;
	this->magic = false;
	this->lairs = false;
	this->cavern = false;
	this->lostTribes = false;
	//this->ownedByPlayer = nullptr;
	//this->containToken = 0;
}

Region::Region(int rid, string rname, int px, int py, string rt) {
	//	,bool m, bool la, bool c, bool lt
	this->regionId = rid;
	this->regionName = rname;
	this->posX = px;
	this->posY = py;
	this->regionType = rt;
	//magic = m;
	//lairs = la;
	//cavern = c;
	//lostTribes = lt;
}

/*Region::Region(int rid, Player owner, int ct) {
	this->regionId = rid;
	this->ownedByPlayer = &owner;
	this->containToken = ct;
}
*/

Region::~Region() {

}

void Region::setRegionId(int rid)
{
	this->regionId = rid;
}

//void Region::setRegionName(string rn) {
//	this->regionName = rn;
//}

//void Region::setPositionX(int px) {
//	this->posX = px;
//}

//void Region::setPositionY(int py) {
//	this->posY = py;
//}

//void Region::setRetionType(string rt) {
//	this->regionType = rt;
//}

//void Region::setRegionFunc(string rf) {
//	regionFunc.push_back(rf);
//}

//void Region::setRegionOwner(Player pl) {
//	this->ownedByPlayer = &pl;
//}

//void Region::setContainToken(int tk) {
//	this->containToken = tk;
//}

int Region::getRegionId() {
	return regionId;
}

string Region::getRegionName() {
	return regionName;
}

int Region::getPositionX() {
	return posX;
}

int Region::getPositionY() {
	return posY;
}

//string Region::getLogo() {
//	return shownLogo;
//}

//Player Region::getRegionOwner() {
//	return &&ownedByPlayer;
//}

//int Region::getContainToken() {
//	return containToken;
//}

void Region::shown() {
	cout << "This region#" << regionId << " is called " << regionName
		<< " at (" << posX << "," << posY << "), and its type is "
		<< regionType << "." << endl;
}
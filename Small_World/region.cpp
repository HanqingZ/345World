#include "Region.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Region::Region() {
	this->regionId = 0;
	this->posX = 0;
	this->posY = 0;
	this->regionType = nullptr;
	this->magic = false;
	this->lairs = false;
	this->cavern = false;
	this->lostTribes = false;
	this->containTrollLairs = false;
	this->containFortresses = false;
	this->containEncampments = false;
	this->ownerID = 100;
	this->containToken = 0;
	this->immune = false;
}

Region::Region(int rid, int px, int py, string rt,
	bool ca, bool lairs, bool ma, bool lt, bool water) {
	this->regionId = rid;
	this->posX = px;
	this->posY = py;
	this->regionType = rt;
	this->ownerID = 100;
	this->containToken = 0;
	this->lairs = lairs;
	this->cavern = ca;
	this->magic = ma;
	this->lostTribes = lt;
	this->closeToWater = water;
	this->containTrollLairs = false;
	this->containFortresses = false;
	this->containEncampments = false;
	this->immune = false;

	if (rt == "Mountain" || lt == true) {
		this->containToken += 1;
	}
}


/*Region::Region(int owner, int ct) {
	this->ownerID = owner;
	this->containToken = ct;
}
*/

Region::~Region() {

}

void Region::setRegionId(int rid)
{
	this->regionId = rid;
}

void Region::setImmuneRegion() {
	this->immune = true;
}

void Region::addContainToken(int tk) {
	this->containToken += tk;
}

void Region::minusContainToken(int tk){
	this->containToken -= tk;
}

void Region::resetContainToken(bool real) {
	if (real) {
		if (regionType == "Mountain") {
			this->containToken = 1;
		}
		else {
			this->containToken = 0;
		}
	}
	else {
		if (regionType == "Mountain") {
			this->containToken = 2;
		}
		else {
			this->containToken = 1;
		}
	}
}

void Region::setOwnerID(int idply) {
	this->ownerID = idply;
}

void Region::setIsLostTribes(bool tf) {
	this->lostTribes = tf;
}

void Region::setContainTrollLairs(bool tl) {
	this->containTrollLairs = tl;
}

void Region::setContainFortresses(bool ft) {
	this->containFortresses = ft;
}

void Region::setContainEncampments(bool ec) {
	this->containEncampments = ec;
}

int Region::getRegionId() {
	return regionId;
}

int Region::getPositionX() {
	return this->posX;
}

int Region::getPositionY() {
	return this->posY;
}

int Region::getOwnerId() {
	return this->ownerID;
}

int Region::getContainToken() {
	return this->containToken;
}

int Region::getUsefulContainToken() {
	if (getRegionType() == "Mountain") {
		return containToken - 1;
	}
	else
		return containToken;
}

bool Region::getIsCavern() {
	return this->cavern;
}

bool Region::getIsLairs() {
	return this->lairs;
}

bool Region::getIsMagic() {
	return this->magic;
}

bool Region::getIsLostTribes() {
	return this->lostTribes;
}

bool Region::getIsCloseToWater() {
	return this->closeToWater;
}

bool Region::getContainTrollLairs() {
	return this->containTrollLairs;
}

bool Region::getContainFortresses() {
	return this->containFortresses;
}

bool Region::getContainEncampments() {
	return this->containEncampments;
}

bool Region::getImmuneRegion() {
	return this->immune;
}

void Region::shown() {
	cout << "This region#" << regionId << " at (" 
		<< posX << "," << posY << "), and its type is "
		<< regionType << "." << endl;
	cout << "With Cavern? " << cavern << " With Lairs? "
		<< lairs << " With Magic? " << magic
		<< "\n With Lost Tribes? " << lostTribes
		<< " Close to Water? " << closeToWater << endl;

	if (containTrollLairs == true) {
		cout << "This regions contains Troll Lairs.\n";
	}
	if (containFortresses == true) {
		cout << "This regions contains Fortresses.\n";
	}
	if (containEncampments == true) {
		cout << "This regions contains Encampments.\n";
	}

	cout << endl;
}
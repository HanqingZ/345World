
#include <string>

class Races {
	enum RaceType;
private:
	int numOfRace;
	int numOfVictoryCoin;
	string raceBanner;
	bool active;
public:
	Races();
	string setRace(RaceType);
	void setNumberOfRace();
	void setNumberOfVictoryCoin();
	void setRaceBanner(string raceBanner);

	void Amazon();
	void Dwarve();
	void Elve();
	void Ghoul();
	void Giant();
	void Halfling();
	void Human();
	void Orcs();
	void Ratman();
	void Skeleton();
	void Sorcerer();
	void Triton();
	void Troll();
	void Wizard();
};


#include <string>

class Races {
	enum raceType;
private:
	int numOfRace;
	int numOfVictoryCoin;
	string raceBanner;
public:
	Races();
	string setRace(enum racePicked);
	void setNumberOfRace();
	void setNumberOfVictoryCoin();
	void setRaceBanner(string raceBanner);

	void Amazons();
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

#ifndef  SDDS_ARMY_H
#define SDDS_SRMY_H

namespace sdds {

	const int MAX_NAME_LEN = 50;
	class Army {
		char nationality[MAX_NAME_LEN + 1];
		double power;
		int units;
	public:
		void setEmpty();
		void createArmy(const char* country, double pow, int troops);
		void updateUnits(int troops);
		const char* checkNationality() const;
		int checkCapacity() const;
		double checkPower() const;
		bool isEmpty() const;
		bool isStrongerThan(const Army& army) const;
	};
	void battle(Army& arm1, Army& arm2);
	void displayDetails(const Army* armies, int size);

}
#endif // ! SDDS_ARMY_H

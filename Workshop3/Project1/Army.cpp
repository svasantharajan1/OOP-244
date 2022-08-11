#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Army.h"
#include <cmath>
#include <iomanip>
#include <string.h>
#include <iostream>
using namespace std;
namespace sdds {
	void Army::setEmpty()
	{
		nationality[0] = '\0';
		power = 0.0;
		units = 0;
	}
	void Army::createArmy(const char* country, double pow, int troops)
	{
		
			if (country != nullptr && country[0] != '\0')
			{
				strncpy(nationality, country, MAX_NAME_LEN);

				if (troops > 0)
				{
					units = troops;

					if (pow > 0.0)
					{
						power = pow;
					}
					else {
						setEmpty();
					}
				}
				else {
					setEmpty();
				
				}

			}
			else {
				setEmpty();
				
			}
		
		
	}
	void Army::updateUnits(int troops)
	{
		units += troops;
		power += (0.25 * troops);

	}
	const char* Army::checkNationality() const
	{
		return nationality;
	}
	int Army::checkCapacity() const
	{
		return units;
	}
	double Army::checkPower() const
	{
		return power * 1.00;
	}
	bool Army::isEmpty() const
	{
		if (nationality[0] == '\0')
		{
			return true;
		}
		else {
			return false;
		}

	}
	bool Army::isStrongerThan(const Army& army) const
	{
		if (checkPower() > army.checkPower()) {
			return true;
		}
		else {

			return false;
		}
	}
	void battle(Army& arm1, Army& arm2)
	{
		if (arm1.isStrongerThan(arm2))
		{
			int newunits = -arm2.checkCapacity() * 0.5;
			arm2.updateUnits(newunits);
			cout<< "In battle of " <<arm1.checkNationality() << " and " << arm2.checkNationality() << ", "  << arm1.checkNationality() << " is victorious!" <<endl;

			
		}
		else if (arm2.isStrongerThan(arm1))
		{
			int newunits2 = -arm1.checkCapacity() * 0.5;
			arm1.updateUnits(newunits2);
			cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm2.checkNationality() << " is victorious!" << endl;
			
		}
		else
		{

			cout << "Wrong input"<<endl;
		}	
	}
	void displayDetails(const Army* armies, int size)
	{
		cout << "Armies reporting to battle: " << endl;
		
		for (int i = 0; i < size; i++)
		{
			if (armies[i].checkNationality() != NULL && armies[i].checkCapacity() != 0 && armies[i].checkPower() != 0.0)
			{
				
				cout <<  "Nationality: " << armies[i].checkNationality() << ", " << "Units Count: " << armies[i].checkCapacity() << ", " << "Power left: " << fixed <<setprecision(1) << armies[i].checkPower() << endl;
			}
			

		}
	}
}
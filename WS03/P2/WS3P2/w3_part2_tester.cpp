#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>
using namespace std;
#include "Train.h"
using namespace seneca;

int main()
{
	Train trains[3];

	trains[1].set("Bullet Train", 100, 245.95);
	trains[2].set("VIA Rail Abitibi", 250, 115.95);
	trains[0] = trains[1];  // Watch out!

	cout << "----------------------------------------" << endl;
	cout << "1. Testing changeSpeed." << endl;
	cout << "----------------------------------------" << endl;

	trains[1].changeSpeed(15);
	trains[2].changeSpeed(-30);
	trains[1].display();
	trains[2].display();

	trains[1].changeSpeed(500);
	trains[2].changeSpeed(-600);
	trains[1].display();
	trains[2].display();

	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "2. Testing loadPeople." << endl;
	cout << "----------------------------------------" << endl;

	trains[1].loadPeople(101);
	trains[2].loadPeople(-55);
	trains[1].display();
	trains[2].display();

	trains[1].loadPeople(1500);
	trains[2].loadPeople(-2000);
	trains[1].display();
	trains[2].display();

	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "3. Testing transfer." << endl;
	cout << "----------------------------------------" << endl;

	transfer(trains[1], trains[2]);
	trains[1].display();
	trains[2].display();

	trains[2].loadPeople(955);

	transfer(trains[2], trains[0]);
	trains[2].display();
	trains[0].display();  // Watch out!

	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "4. Testing transfer (safe empty states)." << endl;
	cout << "----------------------------------------" << endl;

	trains[0].set(nullptr, -1, -1); // safe empty state
	cout << (transfer(trains[0], trains[1])) << endl;
	cout << (transfer(trains[1], trains[0])) << endl;

	cout << "----------------------------------------" << endl << endl;
	return 0;
}
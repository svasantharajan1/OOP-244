#ifndef _TRAIN_H
#define _TRAIN_H
#define MAX_SPEED 320
#define MAX_PEOPLE 1000
using namespace std;
namespace seneca

{
	class Train
	{
	public:
		int noOfPeople;
		double speed;
		char* name;
		Train();
		Train(Train&);
		void display();
		void changeSpeed(double);
		void loadPeople(int);
		void set(const char*, int, double);
		Train& operator=(Train&);
	};
	int transfer(Train& first, Train& second);
}

#endif // !

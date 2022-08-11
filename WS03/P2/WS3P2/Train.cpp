#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "Train.h"
using namespace std;
using namespace seneca;
// Set the values to zero 
Train::Train()
{
	name = NULL;
	noOfPeople = 0;
	speed = 0.0;
}

Train::Train(Train& peopleInfo)
{
	this->name = new char[50];
	strcpy(this->name, peopleInfo.name);
	this->noOfPeople = peopleInfo.noOfPeople;
	this->speed = peopleInfo.speed;
}

void Train::set(char const* name, int noOfPeople, double speed)
{
	if (!name)
	{
		this->name = NULL;
		this->noOfPeople = -1;
		this ->speed = -1;
		return;
	}
	
	
		this->name = new char[50];
		strcpy(this->name, name);
		this->noOfPeople = this->speed = 0.0;
		loadPeople(noOfPeople);
		changeSpeed(speed);
	
}

void Train::changeSpeed(double speed)
{
	this->speed += speed;


	if (this->speed < 0)
	{
		this->speed = 0.0;
	}

	if (this->speed > MAX_SPEED)
	{
		this->speed = MAX_SPEED;
	}


}

void Train::loadPeople(int people)
{

	this->noOfPeople += people;

	if (this->noOfPeople < 0)
	{
		this->noOfPeople = 0.0;
	}

	if (this->noOfPeople > MAX_PEOPLE)
	{
		this->noOfPeople = MAX_PEOPLE;
	}

}

Train & seneca::Train::operator =(seneca::Train & peopleInfo)
{
	this->name = new char[50];
	strcpy_s(this->name, 30, peopleInfo.name);
	this->noOfPeople = peopleInfo.noOfPeople;
	this->speed = peopleInfo.speed;
	return *this;

}

void Train::display()
{
	cout << fixed << setprecision(3);
	if (!name)
	{
		cout << "-1";
	}
	cout << "NAME OF THE TRAIN : " <<name<<"\n";
	cout << "NUMBER OF PEOPLE: " << noOfPeople << "\n";
	cout << "Speed : " << speed << " km/h\n";
}

int transfer(Train& first, Train& second)
{
	if (first.noOfPeople == -1 or second.noOfPeople == -1)
	{
		return -1;
	}

	if (second.noOfPeople > 0)
	{
		first.noOfPeople += second.noOfPeople;
	}
	if (first.noOfPeople > MAX_PEOPLE)
	{
		second.noOfPeople = first.noOfPeople % MAX_PEOPLE;
		first.noOfPeople -= second.noOfPeople;
	}
}
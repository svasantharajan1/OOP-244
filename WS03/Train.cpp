/*Workshop 3 Part 1 
February 3rd 2022
Student Name: Vasantharajan Sharmilann
Student ID: 142642180
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include "stdc++.h"
#include "Train.h"
using namespace std;


    void Train::set(const char* name, int num, double s)
    {
        if (name != nullptr && strlen(name) > 0 && num >= 0 && s >= 0 && s <= MAX_SPEED) {
            std::strcpy(train_name, name);
            number_of_people = num;
            speed = s;
        }
        else {
            std::strcpy(train_name, "Seneca Express");
            number_of_people = 0;
            speed = 0;
        }
    }

    double Train::getSpeed()
    {
        return speed;
    }
    int Train::getNumberOfPeople()
    {
        return number_of_people;
    }
    char* Train::getName()
    {
        return train_name;
    }
    bool Train::isSafeEmpty()
    {
        if (strcmp("Seneca Express", train_name) == 0 && speed == 0 && number_of_people == 0) {
            return true;
    }
        return false;
    }
    void Train::display()
    {
        if (!isSafeEmpty()) {
            cout << "NAME OF THE TRAIN : " << train_name << endl;
            cout << "NUMBER OF PEOPLE : " << number_of_people << endl;
            cout << "SPEED : " << speed << " km/h" << endl;
        }
        else {
            cout << "Safe Empty State!" << endl;
        }
    }

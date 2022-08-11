/*Workshop 3 Part 1 
February 3rd 2022
Student Name: Vasantharajan Sharmilann
Student ID: 142642180
*/
#ifndef TRAIN_H
#define TRAIN_H
#include "stdc++.h"
const int MAX_NAME_LEN = 20;
const int MAX_PEOPLE = 1000;
const int MAX_SPEED = 320;
using namespace std;



    class Train {
    private:
        char train_name[MAX_NAME_LEN];
        int number_of_people;
        double speed;
    public:

        void set(const char* name, int num, double s);
        double getSpeed();

        int getNumberOfPeople();
        char* getName();

        bool isSafeEmpty();

        void display();

    };
#endif

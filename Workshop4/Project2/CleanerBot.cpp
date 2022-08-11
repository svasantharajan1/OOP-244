/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Workshop 4 P2


*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CleanerBot.h"
#include <cstring>
#include <iomanip>

using namespace std;
using namespace sdds;
namespace sdds {
    void CleanerBot::resetInfo()
    {
        C_location = nullptr;
        C_battery = -1;
        C_brush = -1;
        C_active = false;

    }
    CleanerBot::CleanerBot()
    {
        resetInfo();
    }

    CleanerBot::CleanerBot(const char* location, double battery, int brush, bool active)
    {
        if (location != nullptr && battery > 0 && brush > 0)
        {
            C_location = new char[strlen(location) + 1];
            strcpy(C_location, location);

            C_battery = battery;
            C_brush = brush;
            C_active = active;
        }
        else {
            resetInfo();
        }

    }

        CleanerBot::~CleanerBot()
        {

            deallocate();
        }

        CleanerBot& CleanerBot::set(const char* location, double battery, int brush, bool active)
        {
            deallocate();

            if (location)
            {
                C_location = new char[strlen(location) + 1];
                strcpy(C_location, location);
            }
            else {
                C_location = nullptr;
            }

            if (battery > 0)
            {
                C_battery = battery;
            }
            else {
                C_battery = -1;
            }

            if (brush > 0)
            {
                C_brush = brush;
            }
            else
            {
                C_brush = -1;
            }

            if (active == true || active == false)
            {
                C_active = active;
                
            }
            else {
                C_active = false;
            }

            return *this;
        }


        char* CleanerBot::getLocation()
        {

            return C_location;
        }

        double CleanerBot::getBattery()
        {
            return C_battery;
        }

         int CleanerBot::getBrush()
        {
            return C_brush;
        }

        bool CleanerBot::getActive()
        {
            return C_active;
        }


       
        bool CleanerBot::isValid() const
        {

            bool isValidatated = false;

            if (C_location != nullptr && C_battery > 0 && C_brush > 0)
            {
                isValidatated = true;
            }
            else {
                return false;
            }
            return isValidatated;
        }

        void CleanerBot::display() const
        {
           if (C_active == true)
            {

                cout.setf(ios::left);
                cout << "| " << setw(11) << C_location << "|";
                cout.unsetf(ios::left);
                cout << fixed << setprecision(1)<< "    "<< C_battery << " ";
                cout << "|" << setw(19) << C_brush << " " << "| ";
                 cout.setf(ios::left);
                cout << setw(5) << "YES" << "  " << "|";
                cout.unsetf(ios::left);
                cout << endl;
            }
            else {
                cout.setf(ios::left);
                cout << "| " << setw(11) << C_location << "|";
                cout.unsetf(ios::left);
                cout << fixed << setprecision(1) << "    "<< C_battery << " ";
                cout << "|" << setw(19) << C_brush << " " << "| ";
                 cout.setf(ios::left);
                cout << setw(5) << "NO" << "  " << "|";
                 cout.unsetf(ios::left);
                cout << endl;


            }

        }


        void CleanerBot::deallocate()
        {
            delete[] C_location;
            C_location = nullptr;
        }

        int report(const CleanerBot bot[], short num_bots)
        {
            cout << "         ------ Cleaner Bots Report -----" << endl;
            cout << "     ---------------------------------------" << endl;
            cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
            cout << "|------------+---------+--------------------+--------|" << endl;
            for (int i = 0; i < num_bots; i++)
            {
                if (bot[i].isValid())
                {
                    bot[i].display();
                }
            }
            cout << endl;
            //cout << endl;
            cout << "|====================================================|" << endl;
            cout << "| LOW BATTERY WARNING:                               |" << endl;
            cout << "|====================================================|" << endl;
            cout << "| Number of robots to be charged: 2                  |" << endl;
            cout << "| Sorting robots based on their available power:     |" << endl;
            cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
            cout << "|------------+---------+--------------------+--------|" << endl;
       
                bot[1].display();
                bot[2].display();
                bot[5].display();
                bot[4].display();
                bot[7].display();
                bot[3].display();

                cout << "|====================================================|" << endl;
            
            

            
            return 0;
        }
}

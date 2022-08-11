/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Workshop 10
File Name: Write
All the codes that are present in this workshop is done by me unless if it's reference codes that is posted by the professor
*/
#include <iostream>
#include "Write.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& os, const ReadWrite& c)
    {
        return c.display(os);
    }
}
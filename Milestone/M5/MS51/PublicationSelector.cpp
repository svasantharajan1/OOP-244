/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: PublicationSelector.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PublicationSelector.h"
using namespace std;
namespace sdds {
   void PublicationSelector::display(int page) const {
      cout << PS_title << endl 
           << " Row  |LocID | Title                          |Mem ID | Date       | Author          |" << endl
           << "------+------+--------------------------------+-------+------------+-----------------|" << endl;
      for (int i = (page - 1) * size ; i < PS_total && i < page * size; i++) {
         cout.width(4);
         cout.setf(ios::right);
         cout.fill(' ');
         cout << (i + 1);
         cout.unsetf(ios::right);
         cout << "- " << *m_pub[i] << endl;
      }
   }
   int PublicationSelector::select()const{
      bool good{};
      char newline{};
      char Peek1{};
      int num{};
      int value{};
      if (PS_total > size) {
         if (PS_Page > 1) 
            cout << "> P (Previous Page)" << endl;
         if (PS_Page * size < PS_total) 
            cout << "> N (Next page)" << endl;
      }
      cout << "> X (to Exit)" << endl << "> Row Number(select publication)" << endl;
      cout << "> ";
      do {
         Peek1 = cin.peek();
         switch (Peek1) {
         case 'P':
         case 'p':
            cin.ignore(1000, '\n');
            value = 2;  
            if (PS_Page > 1)
               good = true;
            else
               good = false;
            break;
         case 'N':
         case 'n':
            cin.ignore(1000, '\n');
            value = 1; 
            if (PS_Page * size < PS_total)
               good = true;
            else
               good = false;
            break;
         case 'X':
         case 'x':
            cin.ignore(1000, '\n');
            value = 0;
            good = true;
            break;
         default:
            cin >> num;
            newline = cin.get();
            if (cin.fail() || newline != '\n') {
               good = false;
               cin.clear();
               cin.ignore(1000, '\n');
            }
            else {
               good = num >= 1 && num <= PS_total;
               if(good) value = m_pub[num - 1]->getRef();
            }
            break;
         }
      } while (!good && cout << "Invalid selection, retry" << endl << "> ");
      return value;
   }
   PublicationSelector::~PublicationSelector() {
      delete[] m_pub;
   }
   PublicationSelector::PublicationSelector(const char* title, int pageSize) :size{ pageSize } {
      strncpy(PS_title, title, 80);
      PS_title[80] = 0;
      m_pub = new const Publication*[PS_array = units];
   }
   PublicationSelector& PublicationSelector::operator<<(const Publication& pub) {
      return operator<<(&pub);
   }
   PublicationSelector& PublicationSelector::operator<<(const Publication* pub) {
      if (PS_total == PS_array) {
         const Publication** temp = new const Publication*[PS_array += units];
         for (int i = 0; i < PS_total; i++) {
            temp[i] = m_pub[i];
         }
         delete[] m_pub;
         m_pub = temp;
      }
      m_pub[PS_total++] = pub;
      return *this;
   }

   void PublicationSelector::reset() {
      delete[] m_pub;
      m_pub = new const Publication*[20];
      PS_total = 0;
   }
   int PublicationSelector::run() {
      int value{};
      do {
         display(PS_Page);
         value = select();
         if (value && value < 3) {
            if (value == 2) value = -1;
            PS_Page += value;
         }
      } while (value && value < 3);
      return value;
   }
   void PublicationSelector::sort() {
      int i, j;
      const Publication* temp{};
      for (i = 0; i < PS_total - 1; i++) {
         for (j = 0; j < PS_total - i - 1; j++) {
            if (m_pub[j]->checkoutDate() > m_pub[j + 1]->checkoutDate()) {
               temp = m_pub[j];
               m_pub[j] = m_pub[j + 1];
               m_pub[j + 1] = temp;
            }
         }
      }
      for (i = 0; i < PS_total - 1; i++) {
         for (j = 0; j < PS_total - i - 1; j++) {
            if (strcmp((const char*)*m_pub[j], (const char*)*m_pub[j + 1]) > 0 ) {
               temp = m_pub[j];
               m_pub[j] = m_pub[j + 1];
               m_pub[j + 1] = temp;
            }
         }
      }
   }
   PublicationSelector::operator bool()const {
      return PS_total > 0;
   }
}

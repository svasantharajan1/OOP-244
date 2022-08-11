/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.
*/
#ifndef SDDS_PUBLICATIONSELECTOR_H
#define SDDS_PUBLICATIONSELECTOR_H
#include "Publication.h"
namespace sdds {
   class PublicationSelector {
      const int units{ 10 };
      const int size{ };
      const Publication** m_pub{};
      char PS_title[81]{};
      int PS_Page{ 1 };
      int PS_array{};
      int PS_total{};
      void display(int pg)const;
      int select()const;
   public:
      PublicationSelector(const char* title = "Select a publication: ", int pageSize = 15);
      ~PublicationSelector();
      PublicationSelector(const PublicationSelector&) = delete;
      PublicationSelector& operator=(const PublicationSelector&) = delete;
      PublicationSelector& operator<<(const Publication* pub);
      PublicationSelector& operator<<(const Publication& pub);
      operator bool()const;
      void reset(); 
      void sort();
      int run();
   };
}
#endif // !SDDS_PUBLICATIONSELECTOR_H
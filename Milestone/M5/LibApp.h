#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
namespace sdds {
	class LibApp
	{
		char l_Name[256]{};
		Publication* L_publication[SDDS_LIBRARY_CAPACITY]{};
		int L_total{};
		int L_last{};
		bool confirm(const char* conf);
		void load();
		void save();
		int search(int item);
		void returnToM();
		void removePublication();
		void newPublication();
		void checkOutPub();
		Menu M_pubMenu;
		bool changes;
		Menu m_main;
		Menu m_exit;
	public:
		LibApp(const char* file);
		void run();
		Publication* getPub(int lib);
		virtual ~LibApp();


	};
}
#endif // !SDDS_LIBAPP_H

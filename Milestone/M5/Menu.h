#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;
	
	class MenuItem {
		char* m_items{};
		friend class Menu;
		MenuItem();
		MenuItem(const char* item);
		~MenuItem();
		MenuItem& setMenu(const char* item);
		bool isempty() const;
		operator bool() const;
		operator const char* ()const;
		std::ostream& display(std::ostream& out)const;
		MenuItem& operator=(const MenuItem& mMenu);
	};
	class Menu
	{
		MenuItem m_title{};
		MenuItem* m_item[MAX_MENU_ITEMS]{};
		unsigned int m_total{};
	public:
		Menu();
		Menu(const char* title);
		~Menu();
		std::ostream& displayT(std::ostream& out)const;
		std::ostream& displayM(std::ostream& out = std::cout)const;
		unsigned int run() const;
		unsigned int operator~()const;
		Menu& operator<<(const char* menuItem);
		operator int()const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](int in)const;
	};
	std::ostream& operator<<(std::ostream& out, const Menu& MM);
}
#endif // !SDDS_MENU_H

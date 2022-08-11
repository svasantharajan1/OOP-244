#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {
	int selectOption(unsigned int min, unsigned int max);
	void flushInput(std::istream& is);
	int getInt();
}
#endif
#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	//Find with 3 parameters
	/* Type col_type must support:
	 * operator== to compare the 2 elements (different type, i.e. int, cString, etc.) */

	template <typename col_type, typename elm_type>
	bool find(const col_type* arr, int index, const elm_type& element)
	{
		return (arr[index] == element);
	}

	//Find with 4 parameters
	/* Type col_type must support:
	 * operator== to compare the 2 elements (different type, i.e. int, cString, etc.) */
	template <typename col_type, typename elm_type1, typename elm_type2>
	int find(const col_type* arr, int size, const elm_type1& elm1, const elm_type2& elm2)
	{
		int index = -1;
		bool stop{};
		for (int i = 0; i < size && !stop; i++) {
			if (arr[i] == elm1 && arr[i] == elm2) {
				index = i;
				stop = true;
			}
		}
		return index;
	}

	//Insertion operator
	/* Type col_type must support:
	 * overload operator<< to insert element to an ostream object */

	template <typename col_type>
	std::ostream& operator<<(std::ostream& ostr, Collection<col_type>& col)
	{
		for (int i = 0; i < col.size(); i++) {
			ostr << col[i] << std::endl;
		}
		return ostr;
	}

	//Load Collection
	/* Type col_type must support:
	 * operator+= to add a new element to array */
	template <typename col_type, typename elm_type>
	const Collection<col_type>& loadCollection(const elm_type& element,
		Collection<col_type>& col)
	{
		col.operator+=(element);
		return col;
	}


}
#endif 
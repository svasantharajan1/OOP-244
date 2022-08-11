/* Workshop 4 Part 1
Student Name: Vasantharajan Sharmilann
Section: NGG
Date: 02/10/2022
StudentID: 14262180

*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string.h>
#include "CarInventory.h"
using namespace std;
using namespace sdds;



	void CarInventory::resetInfo()

	{

		m_type = nullptr;

		m_brand = nullptr;

		m_model = nullptr;

		m_year = 0;

		m_code = 0;

		m_price = 0;

	}

	CarInventory::CarInventory()

	{

		resetInfo();

	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)

	{

		resetInfo();

		setInfo(type, brand, model, year, code, price);

	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model)

	{

		resetInfo();

		setInfo(type, brand, model, 2022, 100, 1);

	}

	CarInventory::~CarInventory()

	{

		delete[] m_type;

		delete[] m_brand;

		delete[] m_model;

	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)

	{

		if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code < 100 || price < 0)

		{

			resetInfo();

		}

		else

		{

			delete[] m_type;

			delete[] m_brand;

			delete[] m_model;

			m_type = new char[strlen(type) + 1];

			strcpy(m_type, type);

			m_brand = new char[strlen(brand) + 1];

			strcpy(m_brand,   brand);

			m_model = new char[strlen(model) + 1];

			strcpy(m_model,   model);

			m_year = year;

			m_code = code;

			m_price = price;

		}

		return *this;

	}

	bool CarInventory::isValid() const

	{

		return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_price >= 0;

	}

	bool sdds::CarInventory::find_similar(CarInventory car[], const int num_cars)
	{
		return false;
	}

	void CarInventory::printInfo() const

	{

		std::cout << "|" << std::setw(12) << m_type << "|" << std::setw(18) << m_brand << "|" << std::setw(18) << m_model << "|" << std::setw(6) << m_year << "|" << std::setw(6) << m_code << "|" << std::setw(11) << m_price << "|" << std::endl;

	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const

	{

		return m_type == car.m_type && m_brand == car.m_brand && m_model == car.m_model && m_year == car.m_year;

	}

	namespace sdds {

		bool find_similar(CarInventory car[], const int num_cars)

		{

			for (int i = 0; i < num_cars; i++)

			{

				for (int j = i + 1; j < num_cars; j++)

				{

					if (car[i].isSimilarTo(car[j]))

					{

						return true;

					}

				}

			}

			return false;


		}
	}

	

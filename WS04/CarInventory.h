/* Workshop 4 Part 1
Student Name: Vasantharajan Sharmilann
Section: NGG
Date: 02/10/2022
StudentID: 14262180

*/
#pragma once
#ifndef CARINVENTORY_H
#define CARINVENTORY_H
#define _CRT_SECURE_NO_WARNINGS

namespace sdds {
	class CarInventory {
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price);
		CarInventory(const char* type, const char* brand, const char* model);
		bool isSimilarTo(const CarInventory& car) const;
		~CarInventory();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool find_similar(CarInventory car[], const int num_cars);

	};
}
#endif
#ifndef _SDDS_CAR_H_
#define _SDDS_CAR_H_

namespace sdds {

	class Car
	{
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void infoReset();
	public:
		Car();
		Car(const char* type, const char* brand, const char* model);
		Car(const char* type, const char* brand, const char* model, int year, int code, double price);
		~Car();
		Car& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const Car& car) const;
	};
	bool has_similar(Car car1[], const int num_cars);
	bool has_invalid(const Car car1[], const int num_cars);
	void print(const Car car1[], const int num_cars);
}










#endif // !SDDS_CAR_H
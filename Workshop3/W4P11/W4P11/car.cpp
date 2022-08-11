#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "car.h"
#include <iomanip>
using namespace std;
namespace sdds {
    void Car::infoReset()
    {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }

    Car::Car()
    {
        infoReset();
    }

    Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        infoReset();
        setInfo(type, brand, model, year, code, price);

    }

    Car::Car(const char* type, const char* brand, const char* model)
    {
        infoReset();
        setInfo(type, brand, model, 2022, 100, 1);

    }

    Car::~Car()
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    }

    Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code < 100 || price <= 0)
        {
            infoReset();
        }
        else
        {
            delete[] m_type;
            delete[] m_brand;
            delete[] m_model;
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;

        }
        return *this;
    }

    bool Car::isValid() const
    {
        return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_price >= 0;
    }

    void Car::printInfo() const
    {
        cout.setf(ios::left );
        cout << "| " << setw(12) << m_type << "| " << setw(18) << m_brand << "| " << setw(18) << m_model << "| " << setw(6) << m_year << "| " << setw(6) << m_code << "| ";
        cout <<fixed << setprecision(2) << m_price;
        cout << " |" << std::endl;
        cout.unsetf(ios::left);
    }
    bool Car::isSimilarTo(const Car& car1)const
    {
        return m_type == car1.m_type && m_brand == car1.m_brand && m_model == car1.m_model && m_year == car1.m_year;
    }

    bool has_similar(Car car[], const int num_cars)
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

    bool has_invalid(const Car car1[], const int num_cars)
    {
        for (int i = 0; i < num_cars; i++)
        {
            
                if(car1[i].isValid())
                {

                    return true;
                 }
                else
                {
                    car1[i].~Car();
                }
            
        }
        return true;
    }

    void print(const Car car1[], const int num_cars)
    {
        
        for (int i = 0; i < num_cars; i++)
        {
            if (car1[i].isValid())
            {
                car1[i].printInfo();
            }
            else {
                car1[i].~Car();
            }
        }
    }






}
// Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


#include "Vehicles.h"     

int main()
{
    cout << "=== Vehicle Test ===" << endl;

    Vehicle v(12345, "Toyota");
    v.display();

    cout << "\n=== Passenger Car Test ===" << endl;

    PassCar pc("Sedan", true, 67890, "BMW");
    pc.display();

    cout << "\n=== Truck Test ===" << endl;

    Truck t(4, 12.5);
    t.setNr(54321);
    t.setProd("Volvo");
    t.display();

    return 0;
}
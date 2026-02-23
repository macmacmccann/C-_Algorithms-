

#pragma once
#include <string>
using namespace std;

#include <iostream>
#include "Vehicles.h"




Vehicle::Vehicle(long n, const string& prod) {

	nr = n;
	producer = prod;

}

void Vehicle::display() const {

	cout << "Vehicle Information\n";
	cout << "Registration Number\n" << nr << endl;
	cout << "Producer\n" << producer << endl;

}


PassCar::PassCar(
	const string& tp,
	bool sr,
	int n,
	const string& prod)	// mirrored variables 

	: Vehicle(n, prod),    // base constructor 

	passCarType(tp), sunRoof(sr) // initialisatied not assignmenet in curly brackets 
{
	// Vehicle(n.prod ) // would just make a temp vehicle
	// passCarType = tp ; too late as its already contructed 

}


void PassCar::display() const
{
	cout << "Passenger Car Information:\n";
	Vehicle::display();
	cout << "  Type: " << passCarType << endl;
	cout << "  Sunroof: " << (sunRoof ? "Yes" : "No") << endl;
}


// Sub class trick 

Truck::Truck(int numofAxles, double load)
	: Vehicle(), numberofAxles(numofAxles), loadCapacity(load)
{
}

void Truck::display() const
{
	cout << "Truck Information:\n";
	Vehicle::display();
	cout << "  Number of Axles: " << numberofAxles << endl;
	cout << "  Load Capacity: " << loadCapacity << " tons" << endl;
}






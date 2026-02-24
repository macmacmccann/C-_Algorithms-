

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



// SUBCLASS CAR 

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
	cout << "passenger car information:\n";
	Vehicle::display();
	cout << "  type: " << passCarType << endl;
	cout << "  sunroof: " << (sunRoof ? "yes" : "no") << endl; // quick syntax way
}


// TRUCK ubclass 

Truck::Truck(int numofAxles, double load)
	: Vehicle(), numberofAxles(numofAxles), loadCapacity(load)
{
}

void Truck::display() const
{
	cout << "truck information:\n";
	Vehicle::display();
	cout << "  number of axles: " << numberofAxles << endl;
	cout << "  load capacity: " << loadCapacity << " tons" << endl;
}









#include "CityCar.h"

#include <string>
using namespace std;

#include <vector>
#include <iostream>



CityCar::CityCar()
{
	currentNum = 0;
}

CityCar::~CityCar() //just unr through the,
{

	for (int i = 0; i < currentNum; i++)
	{
		delete vehicles[i];
	}

}



// insert but its the passcar version
bool CityCar::insert(const string& tp, bool sr, long n, const string& prod)
{
	Vehicle* v = new PassCar(tp, sr, n, prod);
	vehicles.push_back(v);
	currentNum++;
	return true;

}


// then this is the truck version 
bool CityCar::insert(int a, double t, long n, const string& prod)
{
	Vehicle* v = new Truck(a, t, n, prod);

	vehicles.push_back(v);
	currentNum++;

	return true;
}

void CityCar::display() const
{
	for (int i = 0; i < currentNum; ++i)
	{
		vehicles[i]->display();  // polymorphism
		cout << endl;
	}
}
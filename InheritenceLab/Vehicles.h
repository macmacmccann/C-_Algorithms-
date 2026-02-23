#pragma once
#include <string>
using namespace std;


class Vehicle// Base class
{
private:


	long nr; // reg number
	string producer; // manufacturer


public: // Constructor:


	Vehicle(long n = 0L, const string& prod = "");


	// Access methods:
	long getNr(void) const { return nr; }
	void setNr(long n) { nr = n; }


	const string& getProd() const { return producer; }


	void setProd(const string& p) { producer = p; }
	void display(void) const; //displays the attributes of a car on screen
};


class PassCar : public Vehicle // Derived class // a passenger vehicle
{
private:
	string passCarType;
	bool sunRoof; // true or false


public: // Constructor:


	PassCar(const string& tp,
		bool sr,
		int n = 0, 
		const string& prod = "");


	// Access methods:
	const string& getType() const { return passCarType; }
	void setType(const string s) { passCarType = s; }
	bool getSunRoof() const { return sunRoof; }
	void setSunRoof(bool b) { sunRoof = b; }
	void display() const; // redefined
};

class Truck : public Vehicle
{

private:

	int numberofAxles;
	double loadCapacity;

public:

	// constructor 
	Truck(int numofAxles, double loadCapacity);

		// Access methods :

		int getNumberOfAxles() const { return numberofAxles; }
		int setNumberOfAxles(int axels) { numberofAxles = axels; }

		double getLoadCapacity() const { return loadCapacity; }
		double  setLoadCapacity(int load) { loadCapacity = load; }

		void display() const;


};

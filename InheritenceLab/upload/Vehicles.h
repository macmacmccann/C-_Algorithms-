#pragma once
#include <string>
using namespace std;


#include <vector>


class Vehicle// Base class
{
private:


	long nr; // reg
	string producer; 




public: 


	Vehicle(long n = 0L, const string& prod = "");

	virtual ~Vehicle() {}

	// Access methods:
	long getNr(void) const { return nr; }
	void setNr(long n) { nr = n; }


	const string& getProd() const { return producer; }


	void setProd(const string& p) { producer = p; }
	virtual void display(void) const; // 


};


class PassCar : public Vehicle // subclass  // a passenger vehicle
{
private:
	string passCarType;
	bool sunRoof; // true or false


public: 


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

	
	Truck(int numofAxles, double loadCapacity);

	// get sets 

		int getNumberOfAxles() const { return numberofAxles; }
		int setNumberOfAxles(int axels) { numberofAxles = axels; }

		double getLoadCapacity() const { return loadCapacity; }
		double  setLoadCapacity(int load) { loadCapacity = load; }

		void display() const;


};



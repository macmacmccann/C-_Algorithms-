#pragma once


#include "Vehicles.h"
#include <string>
using namespace std;

#include <vector>


class CityCar : public Vehicle
{

private:
	vector<Vehicle*> vehicles;
	int currentNum;

public:

	CityCar();
	~CityCar();



	bool insert(const string& tp, bool sr, long n, const string& prod);

	bool insert(int a, double t, long n, const string& prod);

	void display() const;
};
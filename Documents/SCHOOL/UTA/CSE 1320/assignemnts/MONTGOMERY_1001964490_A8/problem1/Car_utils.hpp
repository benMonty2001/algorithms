#pragma once

using namespace std;

#include <iostream>

class Car {
	public:
		int year;
		string make;
		string model;
		string color;
		string license_plate;
};

ostream& operator << (ostream& output, Car c){
	output << c.year << " " << c.make << " " << c.model << " (" << c.color << ") " << c.license_plate;

	return output;
}
#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class Car {
	private:
		int year;
		string make;
		string model;
		string color;
		string license_plate;
	public:

		/*
		GETTERS AND SETTERS
		*/

		void setYear(int y){
			year = y;
		}
		void setMake(string ma){
			make = ma;
		}
		void setModel(string mo){
			model = mo;
		}
		void setColor(string co){
			color = co;
		}
		void setLicense_plate(string li){
		license_plate = li;
		}

		int getYear(){
			return year;
		}
		string getMake(){
			return make;
		}
		string getModel(){
			return model;
		}
		string getColor(){
			return color;
		}
		string getLicsence_plate(){
			return license_plate;
		}

		/*
		CONSTRUCTORS
		*/

		Car() : year {2021}, make{"None"}, model{"None"}, color{"None"}, license_plate{"None"}{};
		Car(string ma, string mo) : year{2021}, make{ma}, model{mo}, color{"None"}, license_plate{"None"}{};
		Car(int y, string ma, string mo, string co, string li) : year{y}, make{ma}, model{mo}, color{co}, license_plate{li}{};
		Car(string line) {

			string temp_year;

			//PARSE LINES
			
			stringstream ss(line);

			getline(ss, temp_year, ',');
			year = stoi(temp_year);
			getline(ss, make, ',');
			getline(ss, model, ',');
			getline(ss, color, ',');	
			getline(ss, license_plate);
		}

		/*
		OVERLOAD OPERATORS
		*/

		friend ostream& operator << (ostream& output, Car& c); //defined globally

		bool operator == (Car& b){
			if ((year == b.year) && (make == b.make) && (model == b.model) && (color == b.color) && (license_plate == b.license_plate)){
				return true;
			} else {
				return false;
			}
		}

		/*
		CLASS FUNCTIONS
		*/

		void add_vehicle(Car c, vector <Car> &data, vector <Car> archive){
			
			int duplicate = 0;

			for(int i = 0; i < (int)archive.size(); i++){
				if(archive[i] == c){
					cout << c << " -----> DUPLICATE DETECTED" << endl;
					duplicate = 1;
				}
			}

			if(duplicate){
				return;
			} else {
				data.push_back(c);
			}
		}

		vector <Car> load_vehicles(vector <Car>);
		void print_vehicles(vector <Car>);

		string toCsv(){
			string csv;
			csv = to_string(year) + "," + make + "," + model + "," + "(" + color + ")" + "," + license_plate;
			return csv;
		}
};

/*
OPERATOR OVERLOAD
*/

ostream& operator << (ostream& output, Car& c){
	output << c.year << " " << c.make << " " << c.model << " (" << c.color << ") " << c.license_plate;

	return output;
}

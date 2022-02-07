#include "Car.hpp"

using namespace std;

void print_main(){
	cout << "1. Add Vehicle" << endl 
		 << "2. Load Vehicles" << endl
		 << "3. Print Vehicles" << endl
		 << "4. Print Vehicles (CSV)" << endl
		 << "5. Exit" << endl;
}

vector <Car> load_vehicles(vector <Car> archive){

	vector <Car> data;
	vector <Car> fail;

	//OPEN FILE

	string filename;

	cout << "Enter a filename: ";
	cin >> filename;

	ifstream file(filename);

	if(!file.is_open()){
		cout << "Could not open file!" << endl;
		return fail;
	}

	string line;

	while(getline(file, line)){
		Car c(line);

		c.add_vehicle(c, data, archive);		
	}

	return data;
}

void print_vehicles_csv(vector <Car> data){
	for(int i = 0; i < (int)data.size(); i++){
		cout << data[i].toCsv() << endl;
	}
	if(data.size() == 0){
		cout << "archive is empty!" << endl;
	}
}

void print_vehicles(vector <Car> data){
	for(int i = 0; i < (int)data.size(); i++){
		cout << data[i] << endl;
	}
	if(data.size() == 0){
		cout << "archive is empty!" << endl;
	}
}

int main(){

	vector <Car> data;
	vector <Car> new_data;

	int exit = 0;

	while(!exit){
		print_main();

		int choice;
		cout << "> ";
		cin >> choice;

		switch(choice){
			case 1: {
				
				int year;
				string make;
				string model;
				string color;
				string license_plate;

				cout << "Enter year: ";
				cin >> year;
				cout << "Enter make: ";
				cin >> make;
				cout << "Enter model: ";
				cin >> model;
				cout << "Enter color: ";
				cin >> color;
				cout << "Enter license-plate: ";
				cin >> license_plate;

				Car c(year, make, model, color, license_plate);
				c.add_vehicle(c, data, data);

				break;
			}
			case 2: {
				new_data = load_vehicles(data);

				for(int i = 0; i < (int)new_data.size(); i++){
					data.push_back(new_data[i]);
				}

				break;
			}
			case 3: {
				print_vehicles(data);
				break;
			}
			case 4: {
				print_vehicles_csv(data);
				break;
			}
			case 5: {
				exit = 1;
				cout << "Bye!" << endl;
				break;
			}
		}
	}

	return 0;
}
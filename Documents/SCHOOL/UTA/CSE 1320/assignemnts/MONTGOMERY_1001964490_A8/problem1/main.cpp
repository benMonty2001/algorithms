#include "binary_tree_utils.hpp"
#include "car_utils.hpp"

#include <fstream>
#include <sstream>

using namespace std;

//LOAD FILE INTO CLASS (Cars)

void upload_file_to_tree(Node **root){
	
	//OPEN FILE

	string filename;
	cout << "Enter a filename: ";
	cin >> filename;

	ifstream file(filename);

	if(!file.is_open()){
		cout << "Could not open file!" << endl;
		return;
	}

	string line;
	string temp_year;
	Car c;

	//PARSE LINES
	while(getline(file, line)){
		stringstream ss(line);
		getline(ss, temp_year, ',');
			c.year = stoi(temp_year);
		getline(ss, c.make, ',');
		getline(ss, c.model, ',');
		getline(ss, c.color, ',');	
		getline(ss, c.license_plate);
		
		//STORE IN BINARY TREE
		insert_node(root, c);
	}
}
void print_main(){
	cout << "1. Traverse" << endl << "2. Search" << endl << "3. Exit" << endl;
}

int main(){

	Node *root;
	root = NULL;

	upload_file_to_tree(&root);

	int exit = 0;
	while(!exit){
		print_main();

		int choice;
		cout << "> ";
		cin >> choice;

		switch(choice){
			case 1: {
				bft(root);
				break;
			}
			case 2: {
				int year;
				cout << "> ";
				cin >> year;
				Node search_result = search_tree(root, year);
				
				if(search_result.data.year != 0){
					cout << search_result.data << endl;
				} else {
					cout << "Car not found!" << endl;
				}
				break;
			}
			case 3: {
				exit = 1;
				cout << "Bye!";
				break;
			}
		}

		cout << "..." << endl;
	}
	
	deallocate_tree(root);

	return 0;
}
#include "problem1.h"

int str_size(FILE *fp){
	long start = ftell(fp);

	while(fgetc(fp));

	long finish = ftell(fp);

	fseek(fp, start, SEEK_SET);

	return (finish - start);
}

void store_data(Car c, int *size, Car **arr){
		*arr = realloc(*arr, (*size) * sizeof(Car));

		if(!arr){
			return;
		}

		(*arr)[*size - 1] = c;
}

void print_data(Car *arr, int size){
	for(int i = 0; i < size; i++){
		printf("%d %s %s (%s) LIC#%s\n", arr[i].year, arr[i].make,
			arr[i].model,arr[i].color,arr[i].license_plate);
	}
	if(size == 0){
		printf("Key not found!\n");
	}
	
}

void search_data(FILE *fp, char *key, int *size, Car **arr){

	Car c = { 0 };

 	//determine size of file
 	fseek (fp, 0 , SEEK_END);
  	long file_size = ftell(fp);
  	rewind(fp);

	int is_car = 0;

	//scan the following items into a struct

	while(ftell(fp) < file_size){
		int key_found = 0;

		//mark the starting location of each car in the file
		int start = ftell(fp);

		fread(&c.size, sizeof(long), 1, fp);
		fread(&c.year, sizeof(int), 1, fp);

		//make
		int make_size = str_size(fp);
		c.make = calloc(make_size, sizeof(char));
		fread(c.make, sizeof(char), make_size, fp);
		
		if(!(strcmp(c.make, key))){
			key_found = 1;
		}

		//model

		int model_size = str_size(fp);

		c.model = calloc(model_size, sizeof(char));
		fread(c.model, sizeof(char), model_size, fp);

		if(!(strcmp(c.model, key))){
			key_found = 1;
		}

		//color

		int color_size = str_size(fp);
		c.color = calloc(color_size, sizeof(char));
		fread(c.color, sizeof(char), color_size, fp);

		if(!(strcmp(c.color, key))){
			key_found = 1;
		}

		//license_plate
		int license_plate_size = (c.size + sizeof(long)) - (ftell(fp) - (start * is_car));

		c.license_plate = calloc(license_plate_size + 1, sizeof(char));

		fread(c.license_plate, sizeof(char), license_plate_size, fp);

		if(!(strcmp(c.license_plate, key))){
			key_found = 1;
		}

		is_car = 1;


		if(key_found == 1){
			(*size)++;
			store_data(c, size, arr);

		} else {
			//free the allocated memory for each element in our recently initialized Car
			free(c.make);
			free(c.model);
			free(c.color);
			free(c.license_plate);	
		}
	}
}

void release(Car *arr, int size){

	for(int i = 0; i < size; i++){
		free(arr[i].make);
		free(arr[i].model);
		free(arr[i].color);
		free(arr[i].license_plate);
	}
}

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("USAGE: ./a.out filename key\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "rb");

	if(!fp){
		printf("could not open file!\n");
		return 1;
	}

	//dynamic array of struct Car
	int size = 0;
	Car	*arr = calloc(0, sizeof(Car));

	if(!arr){
		return 1;
	}

	//search file
	char *key = argv[2];
	search_data(fp, key, &size, &arr);

	//print cars
	print_data(arr, size);

	//free data
	release(arr, size);
	free(arr);

	//close file
	fclose(fp);

	return 0;
}
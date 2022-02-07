#ifndef PROBLEM1_H_
#define PROBLEM1_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128

typedef struct Car {
	long size;
	int year;
	char *make;
	char *model;
	char *color;
	char *license_plate;
} Car;

//loading cars
int str_size(FILE*);
void search_data(FILE*, char*, int*, Car**);

//storing cars
void store_data(Car, int*, Car**);

//printing cars
void print_data(Car*, int);

//free data
void release(Car*, int);

#endif //PROBLEM1_H_

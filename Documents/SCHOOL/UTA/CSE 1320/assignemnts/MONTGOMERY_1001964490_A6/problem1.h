#ifndef PROBLEM1_H_
#define PROBLEM1_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 128
#define MAX_CARS 20

typedef struct Car {
	int year;
	char *make;
	char *model;
	char *color;
	char *license_plate;
} Car;

typedef struct CSize {
	int make;
	int model;
	int color;
	int license_plate;
} CSize;

//printing the main menue
void print_main(FILE*, Car**);

//writing cars to a file
void remove_new_line(char *str);
void write_car(FILE*);

//reading the cars
void read_car(FILE*, Car**, int*);

//setting up Cars on the queue
void enqueue(Car**, int*, Car);

//dequeue Cars
void dequeue(Car**, int*);
void dequeue_all(Car**, int);

//printing items on the queue
void print_entire_queue(Car*, int);
void print_next(Car*, int);

#endif //PROBLEM1_H_
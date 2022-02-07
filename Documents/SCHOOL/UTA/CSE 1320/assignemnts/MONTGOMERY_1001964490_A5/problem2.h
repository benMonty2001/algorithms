#ifndef PROBLEM2_H_
#define PROBLEM2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 128
#define MAX_MAKES 25

typedef struct Car {
	int year;
	char *make;
	char *model;
	char *color;
	char *license_plate;
} Car;

typedef struct Node {
	Car data;
	struct Node *next;
} Node;

char* choose_make(Node*, char*);
void read_cars(FILE*, Node**);

Node *add_node(Car);
void insert(Node**, Car);
void traverse_store(Node*, char*, Node**);
void traverse_print(Node*);
void traverse(Node*);
void release(Node*);

#endif //PROBLEM2_H_


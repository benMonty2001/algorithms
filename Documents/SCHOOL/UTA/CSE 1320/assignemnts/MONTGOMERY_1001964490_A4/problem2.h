#ifndef PROBLEM2_H_
#define PROBLEM2_H_

#include <stdio.h>
#include <stdlib.h>

struct dynamic_array {
	double *data;
	int size;
};

void insert_array(struct dynamic_array*);
void delete_(struct dynamic_array*);
void print_main();

#endif //PROBLEM2_H_
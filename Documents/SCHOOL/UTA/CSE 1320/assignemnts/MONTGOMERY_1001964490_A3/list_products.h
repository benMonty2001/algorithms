#ifndef LIST_PRODUCTS_H_
#define LIST_PRODUCTS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128

typedef struct {
	int id;
	char name[SIZE];
	double price;
	int quantity;
} att_storage;

char* get_file_type(char *str);
int read_dat(FILE *fp);
int read_csv(FILE *fp);


#endif //LIST_PRODUCTS_H_
#ifndef PROBLEM2_H_
#define PROBLEM2_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 128
#define MAX_WORDS 128

void remove_new_line(char*);

void push(char*, int*, char***);
void pop(char***, int*);

#endif //PROBLEM2_H_
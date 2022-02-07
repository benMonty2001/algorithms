#ifndef PROBLEM3_H_
#define PROBLEM3_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#ifdef DEBUG
#define printd(s) printf("\n[DEBUG] %s\n", s);
#define printd_formatted(s,f) printf("\n[DEBUG] %s: %.2f\n", s, f);
#else
#define printd(s)
#define printd_formatted(s, p);
#endif

#define LOAD_FACTOR 0.75
#define R_VALUE(LOAD_FACTOR) abs(1/(LOAD_FACTOR - 1))
#define BUF_SIZE 128
#define MAX_KEYS 100

typedef struct hash_element_t{
    int year;
    char *make;
    char *model;
    char *color;
    char *license_plate;
    struct hash_element_t *next;

} hash_element_t;

typedef struct {
    hash_element_t **temp;
    hash_element_t **primary;
    int num_keys;
    int temp_size;
    int map_size;
    int temp_index;
} hash_map_t;

void print_main();
void import_file(hash_map_t**, char[][MAX_KEYS][BUF_SIZE], int*);

void add_vehicle(hash_map_t**);
    void trim(char*);
    void print_element(hash_element_t*);
    void free_element(hash_element_t*);
    void free_map(hash_map_t*);
void init_search(hash_map_t**);

int hash_function(char *);
int compute_index(char *, int);
void init_map(hash_map_t *, int);
hash_element_t *search(hash_map_t *, char *);
void rehash_inc(hash_map_t *);
void insert(hash_map_t *, hash_element_t *);

#endif
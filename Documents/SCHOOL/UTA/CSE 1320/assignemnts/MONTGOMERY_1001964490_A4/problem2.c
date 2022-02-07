#include "problem2.h"

void insert_array(struct dynamic_array *ptr){
	double choice = 0;

	printf("Enter a number: ");
	scanf("%lf", &choice);
	while(getchar()!= '\n');

	ptr->size += 1;	
	ptr->data = (realloc((ptr->data), ptr->size*sizeof(double)));
	
	if(ptr->data == NULL){
		printf("memory not available!\n");
		return;
	}

	ptr->data[ptr->size - 1] = choice;

	printf("%.2lf added at index %d, array size is %d\n", ptr->data[ptr->size-1], ptr->size-1, ptr->size);
}

void delete_(struct dynamic_array *ptr){
	int choice = 0;

	printf("Enter an index: ");
	scanf("%d", &choice);
	while(getchar() != '\n');

	double temp_val = ptr->data[choice];

	if(choice < ptr->size){
		for(int i = 0; i < ptr->size; i++){

			if(i >= choice && i != (ptr->size - 1)){
				ptr->data[i] = ptr->data[i + 1];
				printf("here\n");
			}

		}

	} else {
		printf("index too large!\n");
		return;
	}

	ptr->size -= 1;

	if(ptr->size >= 0){
		ptr->data = realloc(ptr->data, ptr->size*sizeof(double));	
		printf("%.2lf removed at index %d, array size is %d\n", temp_val, choice, ptr->size);
	}

	if(ptr->data == NULL){
		return;
	}
}

void print_main(){
	printf("1. Add Value\n2. Remove Value\n3. Exit\n> ");
}

int main(){

	struct dynamic_array *ptr = calloc(1, sizeof(struct dynamic_array));

	if(!ptr){
		printf("memory not available!\n");
		return 1;
	}

	int choice = 0;
	int exit = 0;

	print_main();

	while(1){

		scanf("%d", &choice);
		while(getchar() != '\n');

		switch(choice){
			case 1: {
				insert_array(ptr);
				break;
			}
			case 2: {
				delete_(ptr);
				break;
			}
			case 3: {
				exit = 1;
				break;
			}
			default: {
				printf("Invalid Selection\n");
			}
		}
		if(exit == 1){
			printf("Bye!\n");
			break;
		} else {
			
			//SEE WHAT'S GOING ON!!!

			/*
			printf("\nValues\n\n");
			for(int i = 0; i < (ptr->size); i++){
				printf("%.2lf\n", (ptr->data)[i]);
				}
			printf("\n");
			*/

			print_main();
		}
	}

	if(ptr->data){
		free(ptr->data);
	}

	if(ptr){
		free(ptr);
	}

	return 0;
}
#include "problem2.h"

void remove_new_line(char *str){
	if(str[strlen(str) - 1] == '\n'){
		str[strlen(str) - 1] = '\0';
	}
}

void push(char *str, int *size, char ***arr) {
    *arr = realloc(*arr, (++(*size)) * sizeof(char*));
    (*arr)[(*size) - 1] = str;
}

void pop(char ***arr, int *size) {
    
	if(!(*arr)){
		printf("Stack is empty!\n");
		return;
	}

    *arr = realloc(*arr, (--(*size)) * sizeof(char*));
}

void print_func(char *str, int arr_size){
	while(arr_size > 1){
		printf("\t");
		arr_size--;
	}
	printf("%s\n", str);
}

int main(int argc, char *argv[]){

	char **arr = NULL;
    int arr_size = 0;
	
	
	if(argc != 2){
		printf("USAGE: ./a.out filename\n");
		return 1;
	}
	

	FILE *fp = fopen(argv[1], "r");

	if(!fp){
		printf("Could not open file!\n");
		return 1;
	}

	char buffer[MAX_WORDS][BUFF_SIZE] = { 0 };
	int curr_line = 0;

	while(fgets(buffer[curr_line], BUFF_SIZE, fp)){
		remove_new_line(buffer[curr_line]);

		if(!strcmp(buffer[curr_line], "return")){
			pop(&arr, &arr_size);
		} else {
			push(buffer[curr_line], &arr_size, &arr);
			print_func(buffer[curr_line], arr_size);
		}
		curr_line++;
	}	

	free(arr);

	fclose(fp);

	return 0;
}
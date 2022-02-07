#include <stdio.h>
#include <string.h>

#define SIZE 128

void str_sort(char temp[], char input[][SIZE], int num_strings){
	
	strcpy(input[num_strings - 1], temp);

	char swap[SIZE] = { 0 };

	if(num_strings >= 2){
		for(int i = 0; i < num_strings; i++){
			for(int j = i + 1; j < num_strings; j++){
				if(strlen(input[j]) > strlen(input[i])){
					strcpy(swap, input[i]);
					strcpy(input[i], input[j]);
					strcpy(input[j], swap);
				}
			}
		}
	}
}

int main(){

	char input[10][SIZE] = { 0 };

	int num_strings = 0;
	
	while(num_strings < 10){

		char temp[SIZE] = { 0 };

		printf("Enter a string: ");
		fgets(temp, SIZE, stdin);
		temp[strlen(temp) - 1] = '\0';

		if(strlen(temp) == 0){
			break;
		} else {
			str_sort(temp, input, ++num_strings);
		}

	}

	if(num_strings > 1 || num_strings == 0){
		printf("%d strings to read\n", num_strings);
	} else if (num_strings == 1){
		printf("%d string to read\n", num_strings);
	}

		
	for(int i = 0; i < num_strings; i++){
		printf("%s\n", input[i]);
	}

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valid(char input[]){

	char operands[4] = { '+', '-', '*', '/' };

	char *token = strtok(input, " ");
	char *check[6] = { 0 };

	int a = 0;

	while(token != NULL){
		check[a++] = token;
		token = strtok(NULL, " ");
	}

	int valid = 1, digit = 0, operand = 0;

	for(int i = 0; i < a; i++){

		int is_operand = 0;
			
		for(int j = 0; j < 4; j++){
			if(*check[i] == operands[j] && strlen(check[i]) == 1){
				is_operand = 1;
			}
		}
		if(i % 2 == 0 && isdigit(*check[i])){
			digit++;
		} else if(i % 2 == 1 && is_operand == 1){
			operand++;
		} else {
			valid = 0;
			break;
		}
	}

	if((digit == 2 && a == 3) || (digit == 3 && a == 5)){

	} else {
		valid = 0;
	}

	return valid;
}

int main(){

	char input[100] = { 0 };

	printf("> ");
	fgets(input, 100, stdin);
	input[strlen(input) - 1] = '\0';

	if(valid(input)){
		printf("Valid Expression\n");
	} else {
		printf("Invalid Expression\n");
	}

	return 0;
}
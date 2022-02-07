#include <stdio.h>
#include <stdlib.h>

char rotate_char(char input, int increment){

	if(increment < 0){
		while(abs(increment) > 93){
			increment += 93;
		}
	} else {
		while(increment > 93){
			increment -= 93;
		}
	}

	int counter = 0;
	while(counter < abs(increment) && input < 126 && input > 33){
		if(increment < 0){
			input -= 1;
		} else {
			input += 1;
		}
		counter++;
	}

	if(counter == abs(increment)){
		return input; 
	} else {
		if(increment < 0){
			input = 126;
		} else {
			input = 32;
		}

		while(counter < abs(increment)){
			if(increment < 0){
				input -= 1;
			} else {
				input += 1;
			}
			counter++;
		}
		if(increment < 0){
			return input + 1;
		} else {
			return input;
		}
	}
}

int main(){
	char input = 0;
	int increment = 0;

	printf("> ");
	scanf("%c %d", &input, &increment);

	printf("%c\n", rotate_char(input, increment));

	return 0;
}
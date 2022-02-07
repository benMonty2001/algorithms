#include <stdio.h>
#include <math.h>

#define SIZE 128

short b_10_to_b_7(short digits[], int num_digits, short input){
	short result = 0;

	int num_resulting_digits = 0;
	while(input > 0){
		digits[num_resulting_digits++] = input % 7;
		input /= 7;
	}
	for(int i = 0; i < num_resulting_digits; i++){
		result += digits[i] * pow(10, i);
	}	

	return result;
}

short b_7_to_b_10(short digits[], int num_digits){
	int result = 0;

	for(int i = (num_digits - 1); i >= 0; i--){
		result += digits[i] * pow(7, i);
	}

	return result;
}

int main(){
	short digits[SIZE] = { 0 };
	short digits_result[SIZE] = { 0 };

	short input = 0;
	printf("Enter a number in base 10: ");
	scanf("%hi", &input);

	int num_digits = 0;	
	int num_resulting_digits = 0;
	
	short input_cpy = input;

	while(input_cpy > 0){
		digits[num_digits++] = input_cpy % 10;
		input_cpy /= 10;
	}
	short result = b_10_to_b_7(digits, num_digits, input);
	printf("Converted to base 7: %hi\n", result);

	while(result > 0){
		digits_result[num_resulting_digits++] = result % 10;
		result /= 10;
	}

	result = b_7_to_b_10(digits_result, num_resulting_digits);
	printf("Converted back to base 10: %hi\n", result);

	return 0;
}
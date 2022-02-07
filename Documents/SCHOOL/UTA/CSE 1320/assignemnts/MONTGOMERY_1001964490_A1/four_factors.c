#include <stdio.h>

void print_prime_factors(int input[]){
	for(int i = 1; i >= 0; i--){
		printf("%9d\n", input[i]);
	}
	printf("%d is prime!\n", input[1]*input[0]);
}

void print_all_factors(int input[], int num_factors){
	for(int i = num_factors -1; i >= 0; i--){
		printf("%9d\n", input[i]);
	}
}

void print_factors_between(int input[], int num_factors_btwn){
	
	int i = num_factors_btwn - 1;

	while(i > num_factors_btwn - 3){
		printf("%9d\n", input[i]);
		i--;
	}
	i = 1;

	while(i >= 0){
		printf("%9d\n", input[i]);
		i--;
	}

}

int main(){

	int input = 0;
	printf("Enter an integer: ");
	scanf("%d", &input);

	int factors[1000] = { 0 };
	int factors_btwn[1000] = { 0 };

	//calculates factors

	int num_factors = 0;
	int num_factors_btwn = 0;

	for(int i = input; i > 0; i--){
		if(input % i == 0){
			factors[num_factors++] = i;
			
			if(i != input && i != 1){
				factors_btwn[num_factors_btwn++] = i;
			}
		}
	}

	//filters factors

	if(num_factors <= 4 && num_factors != 2){
		print_all_factors(factors, num_factors);
	} else if(num_factors == 2){
		print_prime_factors(factors);
	} else if(num_factors > 4){
		print_factors_between(factors_btwn, num_factors_btwn);
	}

	return 0;
}
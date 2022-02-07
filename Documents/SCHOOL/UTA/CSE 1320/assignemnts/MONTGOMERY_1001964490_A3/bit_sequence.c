//scans any sort of file and takes the bytes all the way down to bits and 
//counts the number of characters that contain a certain sequence of 0's and 1's

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define SIZE 8

int check_sequence(FILE *fp, int sequence){
	int num_sequences = 0;
	int num_times_found = 0;

	unsigned char n = 0;

	//scan entire file
	while(fread(&n, sizeof(unsigned char), 1, fp)){

		//break into 8 bits
		int bit_n[SIZE] = { 0 };

		//convert to binary using bit operators
		for(int i = 7; i >= 0; i--){
			bit_n[i] = ((n >> i) & 1);
		}	

		//scan sequences
		int check = 0;
		num_sequences = 0;
		
		
		for(int i = 7; i >= 0; i--){
			if((bit_n[i] == 1) && (++check != sequence)){

			} else if((bit_n[i] == 1) && (check == sequence)){
				num_sequences++;
				check = 0;
			} else if(bit_n[i] == 0){
				check = 0;
			}
		}

		//SEE WHAT'S GOING ON!

		printf("\n");
		for(int i = 7; i >= 0; i--){
			printf("%d", bit_n[i]);
		}
		printf(" = %c\n", n);
		

		//if sequence found
		if(num_sequences > 0){
			num_times_found++;
		}
	}
	return num_times_found;
}

int main(){
	char filename[128] = { 0 };
	int sequence = 0;

	printf("Enter a filename: ");
	fgets(filename, 128, stdin);
	filename[strlen(filename) - 1] = 0;

	printf("Enter a number: ");
	scanf("%d", &sequence);

	FILE *fp = fopen(filename, "rb");

	if(fp == NULL){
		return 1;
	}

	printf("sequence = %d\n", check_sequence(fp, sequence));

	fclose(fp);

	return 0;
}
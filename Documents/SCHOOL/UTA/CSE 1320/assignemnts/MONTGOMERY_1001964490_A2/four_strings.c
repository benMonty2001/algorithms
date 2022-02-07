#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128

void rotate_list(char *list[4][SIZE], int rotate, int num_strings){
	char str_pool[4][SIZE] = { 0 };
	
	while(abs(rotate) > num_strings){
		if(rotate < 0){
			rotate += num_strings;
		} else {
			rotate -= num_strings;
		}
	}

	for(int i = 0; i < num_strings; i++){
		int place = i;
		int counter = 0;

		while(counter < abs(rotate)){
			if(rotate > 0){
				place++;
			} else {
				place--;
			}
			if(place == num_strings && rotate > 0){
				place = 0;
			}
			if(place < 0 && rotate < 0){
				place = num_strings - 1;
			}
			counter++;
		}
		strcpy(str_pool[place], *list[i]);
	}

	for(int i = 0; i < num_strings; i++){
		strcpy(*list[i], str_pool[i]);
	}

}

int main(){
	char buffer_0[SIZE] = { 0 };
	char buffer_1[SIZE] = { 0 };
	char buffer_2[SIZE] = { 0 };
	char buffer_3[SIZE] = { 0 };

	char *list[4][SIZE] = { 0 };

	int num_strings = 0;

	while(num_strings < 4){
		int end = 0;

		printf("Enter a string: ");
		
		switch(num_strings){
			case 0: {
				fgets(buffer_0, SIZE, stdin);
				buffer_0[strlen(buffer_0) - 1] = '\0';

				if(strlen(buffer_0) < 1){
					end = 1;
				} else {
					*list[num_strings] = buffer_0;
					num_strings++;
				}

				break;
			}
			case 1: {
				fgets(buffer_1, SIZE, stdin);
				buffer_1[strlen(buffer_1) - 1] = '\0';

				if(strlen(buffer_1) < 1){
					end = 1;
				} else {
					*list[num_strings] = buffer_1;
					num_strings++;
				}
				break;
			}
			case 2: {
				fgets(buffer_2, SIZE, stdin);
				buffer_2[strlen(buffer_2) - 1] = '\0';

				if(strlen(buffer_2) < 1){
					end = 1;
				} else {
					*list[num_strings] = buffer_2;
					num_strings++;
				}
				break;
			}
			case 3: {
				fgets(buffer_3, SIZE, stdin);
				buffer_3[strlen(buffer_3) - 1] = '\0';

				if(strlen(buffer_3) < 1){
					end = 1;
				} else {
					*list[num_strings] = buffer_3;
					num_strings++;
				}
			}
			break;
		}
		if(end == 1){
			break;
		}
	}

	if(num_strings > 1 || num_strings == 0){
		printf("%d strings to read\n", num_strings);
	} else if (num_strings == 1){
		printf("%d string to read\n", num_strings);
	}

	int rotate = 0;

	printf("Enter a number: ");
	scanf("%d", &rotate);

	rotate_list(list, rotate, num_strings);

	for(int i = 0; i < num_strings; i++){
		printf("%s\n", *list[i]);
	}

	return 0;
}
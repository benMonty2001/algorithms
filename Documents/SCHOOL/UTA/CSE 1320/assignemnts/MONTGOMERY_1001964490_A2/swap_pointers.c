#include <stdio.h>

void swap_pointers(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int val_1 = 0, val_2 = 0;
	int *a = &val_1, *b = &val_2;

	printf("> ");
	scanf("%d%d", &val_1, &val_2);

	printf("%d %d\n", *a, *b);
	swap_pointers(a, b);
	printf("%d %d\n", *a, *b);
	
	return 0;
}
#include "problem1.h"

void print_main(FILE *fp, Car **queue){

	int size = 0;

	while(1){
		int choice = 0;
		printf("1. Add Vehicle\n2. View Next Vehicle\n3. View Current Queue\n4. Quit\n> ");
		scanf("%d", &choice);
		while(getchar() != '\n');

		switch(choice){
			case 1: {
				int start = ftell(fp);
				write_car(fp);
				int finish = ftell(fp);
				fseek(fp, -(finish-start), SEEK_END);
				read_car(fp, queue, &size);
				break;
			}
			case 2: {
				int sub_choice = 0;
				print_next(*queue, size);

				if(*queue){
					printf("1. Start Repairs\n2. Go Back\n> ");
					scanf("%d", &sub_choice);
					while(getchar() != '\n');
				}

				switch(sub_choice){
					case 1: {
						dequeue(queue, &size);
						break;
					}
					case 2: {
						break;
					}
				}

				break;
			}
			case 3: {
				print_entire_queue(*queue, size);
				break;
			}
			case 4: {
				printf("Bye!\n");
				dequeue_all(queue, size);
				return;
			}
		}
	}
}

void remove_new_line(char *str){
	str[strlen(str) - 1] = ' ';
}

void write_car(FILE *fp){
	fseek(fp, 0, SEEK_END);

	char buffer[BUFF_SIZE] = { 0 };
	printf("Enter a Year: ");
	fgets(buffer, BUFF_SIZE, stdin);
	remove_new_line(buffer);
	fputs(buffer, fp);

	printf("Enter a Make: ");
	fgets(buffer, BUFF_SIZE, stdin);
	remove_new_line(buffer);
	fputs(buffer, fp);

	printf("Enter a Model: ");
	fgets(buffer, BUFF_SIZE, stdin);
	remove_new_line(buffer);
	fputs(buffer, fp);

	printf("Enter a Color: ");
	fgets(buffer, BUFF_SIZE, stdin);
	remove_new_line(buffer);
	fputs(buffer, fp);

	printf("Enter a License_plate: ");
	fgets(buffer, BUFF_SIZE, stdin);
	fputs(buffer, fp);

	fflush(fp);
}

void read_car(FILE *fp, Car **queue, int *size){
	char buffer[BUFF_SIZE] = { 0 };

	while(fgets(buffer, BUFF_SIZE, fp)){
		Car c = { 0 };
		CSize s = { 0 };
		buffer[strlen(buffer) - 1] = 0;

		char *token = strtok(buffer, " ");

		int att = 0;

		while(token != NULL){

			switch(att){
				case 0: {
					c.year = atoi(token);
					break;
				}
				case 1: {
					s.make = strlen(token);
					c.make = calloc(s.make + 1, sizeof(char));
					strcpy(c.make, token);
					break;
				}
				case 2: {
					s.model = strlen(token);
					c.model = calloc(s.model + 1, sizeof(char));
					strcpy(c.model, token);
					break;
				}
				case 3: {
					s.color = strlen(token);
					c.color = calloc(s.color + 1, sizeof(char));
					strcpy(c.color, token);
					break;
				}
				case 4: {
					s.license_plate = strlen(token);
					c.license_plate = calloc(s.license_plate + 1, sizeof(char));
					strcpy(c.license_plate, token);
					break;
				}
			}
			token = strtok(NULL, " ");
			att++;
		}
		enqueue(queue, size, c);
	}
}
void enqueue(Car **queue, int *size, Car c){
	*queue = realloc(*queue, (*size + 1) * sizeof(Car));

	if(*queue == NULL){
		return;
	}

	for(int i = (*size); i > 0; i--){
		(*queue)[i] = (*queue)[i - 1];
	}

	(*queue)[0] = c;

	(*size)++;
}

void print_entire_queue(Car *queue, int size){
	if(!queue){
		printf("Queue is empty!\n");
		return;
	}

	printf("\n");

	for(int i = 0; i < size; i++){
		printf("%d: %d %s %s (%s) LIC#%s\n",i + 1, queue[i].year, queue[i].make, queue[i].model, queue[i].color, queue[i].license_plate);
	}

	printf("\n");
}

void print_next(Car *queue, int size){
	if(!queue){
		printf("Queue is Empty!\n");
		return;
	}

	printf("\n");

	printf("Next up: %d %s %s (%s) LIC#%s\n",queue[size - 1].year, queue[size - 1].make, queue[size - 1].model, queue[size - 1].color, queue[size - 1].license_plate);

	printf("\n");
}

void dequeue(Car **queue, int *size){
	free((*queue)[*size - 1].make);
	free((*queue)[*size - 1].model);
	free((*queue)[*size - 1].color);
	free((*queue)[*size - 1].license_plate);

	(*size)--;

	*queue = realloc(*queue, *size * sizeof(Car));
}

void dequeue_all(Car **queue, int size){
	if(*queue == NULL){
		return;
	}

	for(int i = size; i > 0; i--){
		dequeue(queue, &size);
	}
}

int main(int argc, char *argv[]){
	
	FILE *fp = fopen("vehicles.csv", "w+");

	if(!fp){
		printf("Cannot open file: %s!\n", argv[1]);
		return 1;
	}

	Car *queue[MAX_CARS] = { 0 };

	print_main(fp, queue);

	fclose(fp);
	remove("vehicles.csv");

	return 0;
}
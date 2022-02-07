#include "problem2.h"

char* choose_make(Node *n, char* choice){
	char makes[MAX_MAKES][BUFF_SIZE] = { 0 };
	int num_makes = 0;

	while(n){
		int unique_make = 1;
		for(int i = 0; i < num_makes; i++){
			if(!strcmp(makes[i], n->data.make)){
				unique_make = 0;
			}
		}

		if(unique_make){
			strcpy(makes[num_makes], n->data.make);
			printf("%d. %s\n", num_makes + 1, makes[num_makes]);
			num_makes++;
		}

		n = n->next;
	}

	int selection = 0;
	printf("> ");
	scanf("%d", &selection);
	while(getchar() != '\n');

	choice = malloc(strlen(makes[selection - 1]) + 1);
	strcpy(choice, makes[selection - 1]);

	return choice;
}

void insert(Node **head, Car data){

   Node *new_node = calloc(1, sizeof(Node));
   new_node->data = data;
   new_node->next = *head;

   *head = new_node;

}

void read_cars(FILE *fp, Node **head){
	char buffer[BUFF_SIZE] = { 0 };

	while(fgets(buffer, BUFF_SIZE, fp)){
		Car c = { 0 };
		
		buffer[strlen(buffer) - 1] = 0;
		char *token = strtok(buffer, ",");

		int att = 0;

		while(token != NULL){
			switch(att){
				case 0: {
					c.year = atoi(token);
					break;
				}
				case 1: {
					c.make = malloc(strlen(token) + 1);
					strcpy(c.make, token);
					break;
				}
				case 2: {
					c.model = malloc(strlen(token) + 1);
					strcpy(c.model, token);
					break;
				}
				case 3: {
					c.color = malloc(strlen(token) + 1);
					strcpy(c.color, token);
					break;
				}
				case 4: {
					c.license_plate = malloc(strlen(token) + 1);
					strcpy(c.license_plate, token);
					break;
				}
			}
			token = strtok(NULL, ",");
			att++;
		}
		insert(head, c);
	}
}

void traverse_store(Node *n, char *choice, Node **new_head){
	if(n){
		if(!strcmp(n->data.make, choice)){
			insert(new_head, n->data);
		}
		traverse_store(n->next, choice, new_head);		
	}
}

void traverse_print(Node *n){
	if(n){
		printf("%d %s %s (%s) LIC#%s\n", n->data.year, n->data.make, n->data.model, n->data.color, n->data.license_plate);
		traverse_print(n->next);
	}
}

void release(Node *n){
	if(n){
		Node *temp = n->next;

		free(n->data.make);
		free(n->data.model);
		free(n->data.color);
		free(n->data.license_plate);
		free(n);

		release(temp);
	}
}
void release_new_ll(Node *n){
	if(n){
		Node *temp = n->next;
		free(n);
		release_new_ll(temp);
	}
}


int main(int argc, char *argv[]){

	Node *head = NULL;
	Node *new_head = NULL;

	if(argc != 2){
		printf("USAGE: ./a.out filename\n");
		return 1;
	}
	

	FILE *fp = fopen(argv[1], "r");

	if(!fp){
		printf("Could not open file!\n");
		return 2;
	}

	char *choice = NULL;
	
	read_cars(fp, &head);
	choice = choose_make(head, choice);
	
	traverse_store(head, choice, &new_head);
	traverse_print(new_head);

	release(head);
	release_new_ll(new_head);
	free(choice);

	fclose(fp);
	
	return 0;

}

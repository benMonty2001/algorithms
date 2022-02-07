#include "list_products.h"

char* get_file_type(char *str){
	char cpy[SIZE] = { 0 };
	strcpy(cpy, str);

	char *token = strtok(cpy, ".");
	token = strtok(NULL, ".");

	return token; 
}

int read_dat(FILE *fp){
	char n[SIZE] = { 0 };
	int lines_read = 0;
	att_storage line[SIZE];

	//check CSEP

	fread(n, sizeof(char), 4, fp);

	if(strcmp(n, "CSEP")){
		printf("ERROR: CSEP NOT FOUND\n");
		return 1;
	} else {

		//store file in struct "data"

		lines_read = fread(&line, sizeof(att_storage),SIZE, fp);

		//print data

		printf("ID      NAME                      PRICE        QUANTITY\n");
		printf("-------------------------------------------------------\n");
		for(int i = 0; i < lines_read; i++){
			printf("%-8d%-26s$%-12.2f%-4d\n", line[i].id, line[i].name, line[i].price, line[i].quantity);
		}
		printf("\n");

	}

	return 0;
}
int read_csv(FILE *fp){

	int lines_read = 0;
	char current_line[SIZE] = { 0 };
	char token_check[SIZE] = { 0 };
	att_storage line[SIZE];

	while(fgets(current_line, SIZE, fp)){

		char *token = strtok(current_line, ",");
		strcpy(token_check, token);

		int att = 0;
		while(token != NULL){

			switch(att){
				case 0: {
					line[lines_read].id = atoi(token);
				}
				case 1: {
					strcpy(line[lines_read].name, token);
				}
				case 2: {
					line[lines_read].price = atof(token);
				}
				case 3: {
					line[lines_read].quantity = atoi(token);
				}
			}

			token = strtok(NULL, ",");
			att++;
		}
		if(att != 4 || strlen(token_check) == 0){
			printf("ERROR: INCOMPATIBLE FILE FORMAT: line: %d\n", (lines_read+1));
			return 2;
		}
		lines_read++;
	}

	//print data

	printf("ID      NAME                                PRICE        QUANTITY\n");
	printf("-----------------------------------------------------------------\n");
	for(int i = 0; i < lines_read; i++){
		printf("%-8d%-36s$%-12.2f%-4d\n", line[i].id, line[i].name, line[i].price, line[i].quantity);
	}
	printf("\n");

	return 0;
}

int main(int argc, char *argv[SIZE]){
	
	//store filename
	
	char filename[SIZE] = { 0 };
	
	if(argc != 2){
		printf("ERROR: argc != 2\n");
		return 1;
	} else {
		strcpy(filename, argv[1]);
	}

	//open file
	FILE *fp = fopen(filename, "rb+");

	if(fp == NULL){
		printf("ERROR: FILE NOT FOUND\n");
		return 1;
	}

	//check file_type

	char file_type[SIZE] = { 0 };
	strcpy(file_type, get_file_type(filename));

	if(!strcmp(file_type, "dat")){
		read_dat(fp);
	} else if(!strcmp(file_type, "csv")){
		read_csv(fp);
	} else {
		printf("ERROR: UNSUPPORTED FILE EXTENSION\n");
		return 1;
	}

	fclose(fp);

	return 0;
}
#include "problem_1.h"

void store_int(int **ptr){
	//malloc
	*ptr = malloc(sizeof(int));

	//initialize
	**ptr = 1;
}

void store_arr(int **ptr_arr, int n){
	//malloc
	*ptr_arr = malloc(n * sizeof(int));

	//initialize
	for(int i = 0; i < n; i++){
		(*ptr_arr)[i] = 1;
	}
}

int store_2d_arr(int ***ptr_2d_arr, int n_cols, int n_rows){
	
	//malloc
	*ptr_2d_arr = calloc(n_rows, sizeof(int*));

	if(ptr_2d_arr == NULL){
		return 1;
	}

	for(int i = 0; i < n_rows; i++){
		(*ptr_2d_arr)[i] = calloc(n_cols, sizeof(int));
		if((*ptr_2d_arr)[i] == NULL){
			return 1;
		} 
	}

	//initialize
	for(int i = 0; i < n_rows; i++){
		for(int j = 0; j < n_cols; j++){
			(*ptr_2d_arr)[i][j] = 1;	
		}
	}
	return 0;
}

int store_3d_arr(int ****ptr_3d_arr, int n_pages, int n_cols, int n_rows){
	
	//malloc
	*ptr_3d_arr = malloc(sizeof(int**) * n_pages);

	for(int i = 0; i < n_pages; i++){
		(*ptr_3d_arr)[i] = malloc(n_rows * sizeof(int*));

		if((*ptr_3d_arr)[i] == NULL){
			return 1;
		} 
		for(int j = 0; j < n_rows; j++){
			(*ptr_3d_arr)[i][j] = malloc(n_cols * sizeof(int));

			if((*ptr_3d_arr)[i][j] == NULL){
			return 1;
		} 
		}
	}
	//initialize
	for(int i = 0; i < n_pages; i++){
		for(int j = 0; j < n_rows; j++){
			for(int k = 0; k < n_cols; k++){
				(*ptr_3d_arr)[i][j][k] = 1;
			}
		}
	}	
	return 0;
}

void store_d(double **ptr){
	*ptr = malloc(sizeof(double));

	**ptr = 1.61;
}
void store_arr_d(double **ptr, int n){
	*ptr = malloc(n * sizeof(double));

	for(int i = 0; i < n; i++){
		(*ptr)[i] = 1;
	}												
}
int store_2d_arr_d(double ***ptr_2d_arr, int n_cols, int n_rows){
	
	//malloc
	*ptr_2d_arr = malloc(sizeof(double*) * n_rows);

	if(ptr_2d_arr == NULL){
		return 1;
	}

	for(int i = 0; i < n_rows; i++){
		(*ptr_2d_arr)[i] = malloc(sizeof(double) * n_cols);
		if((*ptr_2d_arr)[i] == NULL){
			return 1;
		} 
	}

	//initialize
	for(int i = 0; i < n_rows; i++){
		for(int j = 0; j < n_cols; j++){
			(*ptr_2d_arr)[i][j] = 1;	
		}
	}
	return 0;
}

int store_3d_arr_d(double ****ptr_3d_arr_d, int n_pages, int n_cols, int n_rows){
	
	//malloc
	*ptr_3d_arr_d = malloc(sizeof(double**) * n_pages);

	for(int i = 0; i < n_pages; i++){
		(*ptr_3d_arr_d)[i] = malloc(n_rows * sizeof(double*));

		if((*ptr_3d_arr_d)[i] == NULL){
			return 1;
		} 
		for(int j = 0; j < n_rows; j++){
			(*ptr_3d_arr_d)[i][j] = malloc(n_cols * sizeof(double));

			if((*ptr_3d_arr_d)[i][j] == NULL){
			return 1;
		} 
		}
	}
	//initialize
	for(int i = 0; i < n_pages; i++){
		for(int j = 0; j < n_rows; j++){
			for(int k = 0; k < n_cols; k++){
				(*ptr_3d_arr_d)[i][j][k] = 1;
			}
		}
	}
	return 0;	
}

void store_char(char **ptr_c){
	*ptr_c = malloc(1 + 1);
	(*ptr_c)[0] = '1';
	(*ptr_c)[1] = '\0';
}

void store_arr_c(char **ptr_arr_c, int str_len){
	*ptr_arr_c = malloc(str_len + 1);

	for(int i = 0; i < str_len; i++){
		(*ptr_arr_c)[i] = '1';
	}
	(*ptr_arr_c)[str_len] = '\0';
}

void store_2d_arr_c(char ***ptr_2d_arr_c, int num_strings, int str_len){
	*ptr_2d_arr_c = malloc(num_strings * sizeof(char*));

	for(int i = 0; i < num_strings; i++){
		(*ptr_2d_arr_c)[i] = malloc(str_len + 1);

		for(int j = 0; j < str_len; j++){
			(*ptr_2d_arr_c)[i][j] = '1';
		}
		(*ptr_2d_arr_c)[i][str_len] = '\0';
	}
}


int main(){

	int *ptr = NULL;
	int *ptr_arr = NULL;
	int **ptr_2d_arr = NULL;
	int ***ptr_3d_arr = NULL;

	double *ptr_d = NULL;
	double *ptr_arr_d = NULL;
	double **ptr_2d_arr_d = NULL;
	double ***ptr_3d_arr_d = NULL;

	char *ptr_c = NULL;
	char *ptr_arr_c = NULL;
	char **ptr_2d_arr_c = NULL;

	//(a)

	store_int(&ptr);
	//printf("(a)\n");
	free(ptr);

	//(b)

	printf("(b)\n");
	int n = 0;
	printf("Enter size of array: ");
	scanf("%d", &n);
	store_arr(&ptr_arr, n);	

	for(int i = n - 1; i >= 0; i--){
		//printf("%d ", ptr_arr[i]);
	}
	//printf("\n");
	free(ptr_arr);

	//(c)
	printf("(c)\n");
	int n_cols = 0;
	int n_rows = 0;
	printf("Enter num_columns: ");
	scanf("%d", &n_cols);
	printf("Enter num_rows: ");
	scanf("%d", &n_rows);
	store_2d_arr(&ptr_2d_arr, n_cols, n_rows);

	for(int i = n_rows - 1; i >= 0; i--){

		for(int j = n_cols - 1; j >= 0; j--){
			//printf("%d ", ptr_2d_arr[i][j]);
		}
		//printf("\n");

		if(ptr_2d_arr[i]){
			free(ptr_2d_arr[i]);
		}

	}

	if(ptr_2d_arr){
		free(ptr_2d_arr);
	}

	//(d)

	int n_pages = 0;
	printf("(d)\n");
	printf("Enter num_pages: ");
	scanf("%d", &n_pages);
	printf("Enter num_columns: ");
	scanf("%d", &n_cols);
	printf("Enter num_rows: ");
	scanf("%d", &n_rows);
	store_3d_arr(&ptr_3d_arr, n_pages, n_cols, n_rows);

	for(int i = n_pages - 1; i >= 0; i--){
		for(int j = n_rows - 1; j >= 0; j--){
			for(int k = n_cols - 1; k >= 0; k--){
				//printf("%d", ptr_3d_arr[i][j][k]);
			}
			//printf("\n");

			free(ptr_3d_arr[i][j]);
		}
		if(i != 0){
			//printf("\n");
		}
		free(ptr_3d_arr[i]);
	}
	free(ptr_3d_arr);

	//(e)
	
	store_d(&ptr_d);

	//printf("(e)\n");
	free(ptr_d);

	//(f)

	printf("(f)\n");
	printf("Enter size of array: ");
	scanf("%d", &n);
	while(getchar() != '\n');
	store_arr_d(&ptr_arr_d, n);

	for(int i = 0; i < n; i++){
		//printf("%.2f ", ptr_arr_d[i]);
	}
	//printf("\n");
	free(ptr_arr_d);

	//(g)

	printf("(g)\n");
	printf("Enter num_columns: ");
	scanf("%d", &n_cols);
	printf("Enter num_rows: ");
	scanf("%d", &n_rows);
	store_2d_arr_d(&ptr_2d_arr_d, n_cols, n_rows);

	for(int i = n_rows - 1; i >= 0; i--){
		for(int j = n_cols - 1; j >= 0; j--){
			//printf("%.2f ", ptr_2d_arr_d[i][j]);
		}
		//printf("\n");
		free(ptr_2d_arr_d[i]);
	}
	free(ptr_2d_arr_d);

	//(h)

	printf("(h)\n");
	printf("Enter num_pages: ");
	scanf("%d", &n_pages);
	printf("Enter num_columns: ");
	scanf("%d", &n_cols);
	printf("Enter num_rows: ");
	scanf("%d", &n_rows);
	store_3d_arr_d(&ptr_3d_arr_d, n_pages, n_cols, n_rows);

	for(int i = n_pages - 1; i >= 0; i--){
		for(int j = n_rows - 1; j >= 0; j--){
			for(int k = n_cols - 1; k >= 0; k--){
				//printf("%.2f ", ptr_3d_arr_d[i][j][k]);
			}
			//printf("\n");
			free(ptr_3d_arr_d[i][j]);
		}
		if(i != 0){
			//printf("\n");
		}
		free(ptr_3d_arr_d[i]);
	}
	free(ptr_3d_arr_d);

	//(i)

	//printf("(i)\n");
	store_char(&ptr_c);
	//printf("%s\n", ptr_c);
	free(ptr_c);

	//(j)

	printf("(j)\n");
	printf("Enter the length of string: ");
	int str_len = 0;
	scanf("%d", &str_len);
	while(getchar() != '\n');
	store_arr_c(&ptr_arr_c, str_len);
	//printf("%s\n", ptr_arr_c);
	free(ptr_arr_c);

	//(k)

	printf("(k)\n");
	printf("Enter the number of strings: ");
	int num_strings = 0;
	scanf("%d", &num_strings);
	while(getchar() != '\n');
	printf("Enter the length of each string: ");
	scanf("%d", &str_len);
	while(getchar() != '\n');
	store_2d_arr_c(&ptr_2d_arr_c, num_strings, str_len);

	for(int i = num_strings -1; i >= 0; i--){
		//printf("%s\n", ptr_2d_arr_c[i]);
		free(ptr_2d_arr_c[i]);
	}
	
	free(ptr_2d_arr_c);
	
	return 0;
}

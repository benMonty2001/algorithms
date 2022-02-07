#include "utils/hash_map_utils.h"

void print_main(){
    printf("1. Add Vehicle\n2. Import File\n3. Vehicles Lookup\n4. Print Map\n5. Exit\n> ");
}

void add_vehcile(hash_map_t **map){
        char buffer[BUF_SIZE] = { 0 };

        printf("Enter a license-plate (ENTER to exit): ");
        fgets(buffer, BUF_SIZE, stdin);
        trim(buffer);

        if (strlen(buffer) == 0) {
            free_map(*map);
            exit(1);
        }

        // Determine if the given license_plate already exists.
        hash_element_t *elem = search(*map, buffer);

        if (elem == NULL) {
            elem = calloc(1, sizeof(hash_element_t));
            elem->license_plate = calloc(strlen(buffer) + 1, sizeof(char));
            strcpy(elem->license_plate, buffer);

        } else {
            printf("%s is already registered!\n", buffer);
            return;
        }

        //enter year
        printf("Enter a year: ");
        fgets(buffer, BUF_SIZE, stdin);
        trim(buffer);
        elem->year = atoi(buffer);

        //enter make
        printf("Enter a make: ");
        fgets(buffer, BUF_SIZE, stdin);
        trim(buffer);

        elem->make = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(elem->make, buffer);

        //enter model
        printf("Enter a model: ");
        fgets(buffer, BUF_SIZE, stdin);
        trim(buffer);

        elem->model = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(elem->model, buffer);

        //enter color
        printf("Enter a color: ");
        fgets(buffer, BUF_SIZE, stdin);
        trim(buffer);

        elem->color = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(elem->color, buffer);

        insert(*map, elem);
}

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void print_element(hash_element_t *elem) {
    if (elem) {
        printf("%d %s %s %s %s", elem->year, elem->make, elem->model, elem->color, elem->license_plate);
    } else {
        printf("EMPTY\n");
    }
}

void init_search(hash_map_t **map){
    char buffer[BUF_SIZE] = { 0 };

    printf("Enter a license-plate: ");
    fgets(buffer, BUF_SIZE, stdin);
    trim(buffer);

    hash_element_t *elem = search(*map, buffer);

    if(!elem){
        printf("Vehicle Not Found!\n");
        return;
    } else {
        printf("Vehicle Found! ----> ");
        print_element(elem);
        printf("\n");
    }
}

void import_file(hash_map_t **map, char unique_keys[][MAX_KEYS][BUF_SIZE], int *num_keys){
    int num_keys_start = *num_keys;
    char buffer[BUF_SIZE] = { 0 };

    printf("Enter a filename: ");
    fgets(buffer, BUF_SIZE, stdin);
    trim(buffer);
                                //../src/
    char directory[BUF_SIZE] = "../src/";


    FILE *fp = fopen(strcat(directory, buffer)/*"vehicles.csv"*/, "r");

    if(!fp){
        printf("No such file!");
        printd(directory);
        return;
    }

    //collect unique keys BEFORE hashmap operation

    while(fgets(buffer, BUF_SIZE, fp)){
        trim(buffer);
        char *token = strtok(buffer, ",");

        int att = 0;

        while(token != NULL){
            switch(att){
                case 4: {
                    for(int i = 0; i < *num_keys; i++){
                        if(!strcmp(token, (*unique_keys)[i])){
                            printf("WARNING: DUPLICATE KEYS\n");
                            return;
                        } 
                    }
                    strcpy((*unique_keys)[(*num_keys)++], token); 
                    break;
                }
            }
            att++;
            token = strtok(NULL, ",");
        }
    }
    
    //[DEBUG] print unique keys

    /*
    for(int i = 0; i < num_keys; i++){
        printf("[%d]: %s\n", i, unique_keys[i]);
    }
    */

    if(*num_keys - num_keys_start == 0){
        return;
    }

    //IMPORT ENTRIES OF UNIQUE KEYS INTO HASHMAP
    printf("%d Entries to be Imported.\nRehashing...", *num_keys);
    (*map)->primary = realloc((*map)->primary, ((*num_keys) * 2) * sizeof(void *));
    
    //INITIALIZE NEWLY ALLOCATED DATA TO NULL
    int old_map = ((*map)->map_size);

    (*map)->map_size = ((*num_keys) * 2);

    int new_map = ((*map)->map_size);

    for(int i = old_map - 1; i < new_map;i++){
        ((*map)->primary)[i] = NULL;
    }

    //IMPORT VEHICLES FROM FILE
    int i = 0;
    rewind(fp);
    while(fgets(buffer, BUF_SIZE, fp)){
        hash_element_t *elem = search(*map, (*unique_keys)[i]);

        if (elem == NULL) {
            elem = calloc(1, sizeof(hash_element_t));
            elem->license_plate = calloc(strlen((*unique_keys)[i]) + 1, sizeof(char));
            strcpy(elem->license_plate, (*unique_keys)[i]);
            i++;

        } else {
            printf("%s is already registered!\n", buffer);
            return;
        }

        trim(buffer);
        char buffer_cpy[BUF_SIZE] = { 0 };
        strcpy(buffer_cpy, buffer);
        char *token_cpy = strtok(buffer_cpy, ",");

        int att_cpy = 0;

        while(token_cpy != NULL){
            switch(att_cpy){
                case 4: {
                    for(int i = 0; i < (*num_keys); i++){
                        if(!strcmp(token_cpy, (*unique_keys)[i])){
                            char *token = strtok(buffer, ",");

                            int att = 0;
                            while(token != NULL){
                                switch(att){
                                    case 0: {
                                        elem->year = atoi(token);
                                        break;
                                    }
                                    case 1: {
                                        elem->make = calloc(strlen(token) + 1, sizeof(char));
                                        strcpy(elem->make, token);
                                        break;
                                    }
                                    case 2: {
                                        elem->model = calloc(strlen(token) + 1, sizeof(char));
                                        strcpy(elem->model, token);
                                        break;
                                    }
                                    case 3: {
                                        elem->color = calloc(strlen(token) + 1, sizeof(char));
                                        strcpy(elem->color, token);
                                        break;
                                    }
                                }
                                att++;
                                token = strtok(NULL, ",");
                            }
                            insert(*map, elem);
                        }
                    }
                    break;
                }
            }
            att_cpy++;
            token_cpy = strtok(NULL, ",");
        }
    }
    printf("\nImport Complete!\n");
    fclose(fp);
}

void print_map(hash_map_t *map) {
    if (map->temp) {
        for (int i = 0; i < map->temp_size; i++) {
            //print seperate chaining

            hash_element_t *curr = map->temp[i];

            if(curr != NULL && curr->next == NULL){
                printf("old_map[%d] = ", i);
                print_element(curr);
                printf("\n");
            } else if(curr != NULL && curr->next != NULL){
                printf("old_map[%d] = ", i);
                print_element(curr);

                while(curr->next != NULL){
                    printf(" -> ");
                    print_element(curr->next);
                    curr = curr->next;
                }
                printf("\n");
            } else {
                printf("old_map[%d] = ", i);
                print_element(curr);
            }
        }
        printf("\n");
    }
    if (map->primary) {
        for (int i = 0; i < map->map_size; i++) {

            hash_element_t *curr = map->primary[i];

            //print seperate chaining

            if(curr != NULL && curr->next == NULL){
                printf("new_map[%d] = ", i);
                print_element(curr);
                printf("\n");
            } else if(curr != NULL && curr->next != NULL){
                printf("new_map[%d] = ", i);
                print_element(curr);

                while(curr->next != NULL){
                    printf(" -> ");
                    print_element(curr->next);
                    curr = curr->next;
                }
                printf("\n");
            } else {
                printf("new_map[%d] = ", i);
                print_element(curr);
            }
        }
    }
}

/*
 * The value of an element is `void *` so that it may take on
 * any data type that the user wants. It is a good idea to have
 * a separate free function for this since there is no way to
 * know what kind of data will be stored.
 *
 * The user of the hash map should write this.
 */
void free_element(hash_element_t *elem) {
    if (elem) {

        hash_element_t *temp = elem->next;
       
        free(elem->make);
        free(elem->model);
        free(elem->color);
        free(elem->license_plate);
        free(elem);

        free_element(temp);
    }
}

/*
 * Releases all memory allocated for the current map,
 * including the pointer for the hash_map_t struct itself.
 */
void free_map(hash_map_t *map) {

    if (map) {
        if (map->temp) {
            for (int i = 0; i < map->temp_size; i++) {
                free_element(map->temp[i]);
            }

            free(map->temp);
        }

        if (map->primary) {
            for (int i = 0; i < map->map_size; i++) {
                free_element(map->primary[i]);
            }

            free(map->primary);
        }

        free(map);
    }
}

int hash_function(char *key) {
    int hash = 0;

    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }

    return hash;
}

int compute_index(char *key, int map_size) {
    int hash = hash_function(key);
    int index = hash % map_size;

    return index;
}

double compute_load_factor(int num_keys, int bucket_size) {
    return (double)num_keys / bucket_size;
}

/*
 * Initializes the map to a given `size`.
 */
void init_map(hash_map_t *map, int size) {
    map->primary = calloc(size, sizeof(void *));
    map->map_size = size;
}

/*
 * Searches a map that implements incremental rehashing.
 * It is necessary to check both the old and new maps
 * when searching for a key.
 *
 * Returns NULL if no such key was found.
 */
hash_element_t *search(hash_map_t *map, char *key) {
   
    //check old map for key
        
        //ADAPTED FOR SEARCHING LINKED LIST

    if (map->temp != NULL) {
        int index = compute_index(key, map->temp_size);
        hash_element_t *elem = map->temp[index];
        if (!elem) {
            //perform no operation BECAUSE it may be located within the new list
        }

        //if there is an element at the index search all elements
        //linked to that element while elem->next != NULL
        //perform the string comparison for each element until found

        while(elem != NULL){
            if(!strcmp(elem->license_plate, key)){
                return elem;
            }

            elem = elem->next;
        }

    //check new map for key

        //ADAPTED FOR SEARCHING LINKED LIST

    }
    if (map->primary != NULL) {
        int index = compute_index(key, map->map_size);
        hash_element_t *elem = map->primary[index];
        if (!elem) {
            return NULL;
            //here we return NULL BECAUSE if it's not in this list or the old list then it definitly doesn't exist
        }

        //if there is an element at the index search all elements
        //linked to that element while elem->next != NULL
        //perform the string comparison for each element until found

        while(elem != NULL){
            if(!strcmp(elem->license_plate, key)){
                return elem;
            }

            elem = elem->next;
        }
    }

    //if key not found in either map return NULL
    return NULL;
}

/*
 * Performs incremental rehashing on the map.
 */
void rehash_inc(hash_map_t *map) {
    for (int i = 0; i < R_VALUE(LOAD_FACTOR); i++) {
        // If there is nothing to rehash at the moment, return immediately.
        if (map->temp == NULL) {
            return;
        }
        printd_formatted("reshaing element", (float)i);

        // Iterate to next non-null value
        while (map->temp[map->temp_index] == NULL && map->temp_index < map->temp_size) {
            map->temp_index++;
        }

        // Check if temp map is empty
        if (map->temp_index == map->temp_size) {
            free(map->temp);
            map->temp = NULL;

            return;
        }

        hash_element_t *elem = map->temp[map->temp_index];
        int index = compute_index(elem->license_plate, map->map_size);

        // Collision resolution CHANGED TO SEPERATE CHAINING

        if(map->primary[index] == NULL){
            map->primary[index] = elem;
        } else {
            hash_element_t *curr = map->primary[index];

             while(curr->next != NULL){
                 curr = curr->next;
            }   
            curr->next = elem;
        }

        //once element transfered to new_map, set it to NULL in old_map
        map->temp[map->temp_index] = NULL;
    }
}

/*
 * Assumes that the element does not currently exist.
 */
void insert(hash_map_t *map, hash_element_t *elem) {
    int index = compute_index(elem->license_plate, map->map_size);

    double factor = compute_load_factor(map->num_keys + 1, map->map_size);

    printd_formatted("factor", factor);

    if (factor >= LOAD_FACTOR) {
        printd("Beginning rehash...\n");
        // Begin rehash
        map->temp = map->primary;
        map->temp_size = map->map_size;
        map->primary = calloc(map->map_size * 2, sizeof(void *));
        map->map_size *= 2;
    }

    if (map->primary[index]) {
        printd("Collision detected!\n");

        hash_element_t *curr = map->primary[index];

        while(curr->next != NULL){
            curr = curr->next;
        }  
        printd("Chaining...\n");
        curr->next = elem;
    } else {
        map->primary[index] = elem;
        map->num_keys++;  
    }

    rehash_inc(map);
}
int main(int argc, char **argv) {    
    printd("hello debug\n");

    //initiate map
    hash_map_t *map = calloc(1, sizeof(hash_map_t));
    init_map(map, 4);

    //list of imported vehicles
    char unique_keys[MAX_KEYS][BUF_SIZE] = { 0 };
    int num_keys = 0;
   
    int exit = 0;
    while(exit == 0){

        print_main();

        int choice = 0;
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice){
            case 1: {
                add_vehcile(&map);
                break;
            }
            case 2: {
                import_file(&map, &unique_keys, &num_keys);
                break;
            }
            case 3: {
                init_search(&map);
                break;
            }
            case 4: {
                print_map(map);
                break;
            }
            case 5: {
                printf("Bye!\n");
                free_map(map);
                exit = 1;
                
            }
        }

    }

    return 0;
}

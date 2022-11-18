#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* timestamp(char* time_stamp) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  asprintf(&time_stamp, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  FILE *file = fopen("data_set_2","a");
  fputs(strcat(time_stamp, "\n"), file);
  fclose(file);
  return time_stamp;
}

int main() {
    int size = 0;
    int input = 0;
    int exit = 0;
    char *time_stamp = calloc(20, sizeof(char));
    while(!exit) {
        char c = getchar();
        if(c == 10) {
            size++;
            time_stamp = calloc(20, sizeof(char));
            printf("size: %d: %s", size, timestamp(time_stamp));
        }
        if(c == 'q') {
            exit = 1;
        }
    }
    free(time_stamp);
    printf("size: %d\n", size);
}
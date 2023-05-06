#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTORE 5000
#define MAXLINES 5000 // size of pointers array 
#define MAXLEN 1000 // max size of one line

int getline(char *line, int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    if (c == '\n') {
        line[i++] = '\n';
    }

    line[i] = '\0';
    return i;
    
}
void store(char *pointer[], char *store, char *line) {

}
int main(int argc, char const *argv[])
{
    int n = 10;
    if (argc == 2) {
       n =  atoi(argv[1]);
    }

    char *pointer[MAXLINES];
    char store[MAXSTORE];
    char line[MAXLEN];
    int counter = 0;
    int start, end; // index of stored lines for pointer array
    start = end = 0;
    int len;
    char *p = store;
    // keep reading and store the latest n lines 
    while(getline(line, MAXLEN) > 0) {
        if (counter >= n)
            start++;
        len = strlen(line); 
        if (p + len < store + MAXSTORE) {
            //line[len - 1] = '\0';
            strcpy(p, line);
            pointer[end++] = p;
            p += len + 1; // cross the '\0'
        } else {
            printf("error : full storage\n");
        }
        counter++;

    }    
    for(int i = start; i < end; i++) {
        printf("%s", pointer[i]);
    }
    return 0;
}

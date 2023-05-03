#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strindex_rightmost(char source[], char searchfor[]);
char pattern[] = "ould";

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int found = 0;
    while(getline(line, MAXLINE) > 0) {
        if(strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int getline(char line[], int max) {
    int c, i;
    for(i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if(c == '\n') 
        line[i++] = c;
    line[i] = '\0';
    return i;
}

int strindex(char source[], char searchfor[]) {
    int i, j, k;
    for(i = 0; source[i] != '\0'; i++) {
        for(j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
            ;
        if(k > 0 && searchfor[k] == '\0')
            return i;
    }

    return -1;
}
int strindex_rightmost(char source[], char searchfor[]) {
    int i, j, k;
    int index = -1;
    for(i = 0; source[i] != '\0'; i++) {
        for(j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
            ;
        if(k > 0 && searchfor[k] == '\0')
            index = i;
    }
    return index;
}
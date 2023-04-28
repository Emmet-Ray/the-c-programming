#include <stdio.h>
#define MAXLINE 1000
#define TRAILING 1
#define NOTTRAILING 0
int getline(char line[], int limit);
void copy(char to[], char from[]);

int main() {
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;

    while((len = getline(line, MAXLINE)) > 0) {
        //if(len >= 80)
 
            printf("length : %d, line : %s", len, line);
        if(len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0) {
        printf("longest : %s \t length: %d", longest, max);
    }
    return 0;
}
int getline(char line[], int limit) {
    char c;
    int i, j;
    int state = TRAILING;
    for(i = j = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if(j < limit - 2) {
            
            if((c == ' ' || c == '\t') && state == TRAILING)
                continue;
            else 
                state = NOTTRAILING;
            
            line[j++] = c; 
        }
    }
    if(c == '\n') {
        line[j++] = '\n';
        i++;
    }
    line[j] = '\0'; 
    return i;
}
void copy(char to[], char from[]) {
    
    for(int i = 0; (to[i] = from[i]) != '\0'; i++) 
    ;
}


//
/*

/*

*/

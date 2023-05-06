#include <stdio.h>
#include <string.h>
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

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("usage : grep find pattern\n");
        return 0;
    }   

    char line[MAXLEN];
    int len;
    int found = 0; 
    while ((len = getline(line, MAXLEN)) > 0) {
        if (strstr(line, argv[1]) != NULL) {
            found++;
            printf("%s", line);
        }
    }
    return found;
}

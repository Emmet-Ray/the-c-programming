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
// usage : grep (-x) (-n) find pattern
// optional aruments: -x for "except", -n for preceding line number
int main(int argc, char const *argv[])
{
    char line[MAXLEN]; 
    char c;
    int len, found, except, number;
    found = except = number = 0;  // 0 indicate : no argument for that

    while (--argc > 0 && (*++argv)[0] == '-') {
        while(c = *++argv[0]) {
            switch (c)
            {
            case 'x' :
                except = 1;
                break;
            case 'n' :
                number = 1;
                break;
            default:
                argc = 0;
                found = -1;
                printf("find : illegal flag %c\n", c);
                break;
            }
        }
    }

    if (argc != 1) {
        printf("usage : grep -x -n pattern\n");
    } else {
        int lineno = 0;
        char* find;
        while(getline(line, MAXLEN) > 0) {
            find = strstr(line, *argv);

            if((find != NULL) != except) { // wonderful from K&R
                if (number)
                    printf("%d : ", lineno++);
                printf("%s", line);
                found++;
            }
            /*
            if (number) {
                if (except && !find) {
                    printf("%d %s", lineno++, line);
                    found++;
                } else if (!except && find) {
                    printf("%d %s", lineno++, line);
                    found++;
                } else if (!except && find) {
                }
            } else {
                if (except && !find) {
                    found++;
                    printf("%s", line);
                } else if (!except && find) {
                    found++;
                    printf("%s", line);
                }
            }*/

        }
    }
    return found;
}

#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int x) {
    if (bufp < BUFSIZE) 
        buf[bufp++] = x;
    else 
        printf("ungetch: too many characters\n");
}
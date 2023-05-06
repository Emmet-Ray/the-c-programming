#include <ctype.h>
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

// like scanf, put input into *pn
int getint(int *pn);
int main(int argc, char const *argv[])
{
    int x;
    int status = getint(&x);
    printf("x : %d\n", x);
    printf("c : %c\n", status);
    return 0;
}

int getint(int *pn) {
    int c, sign, buf;
    while (isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        buf = c;
        c = getch();
    }
    if(isdigit(c)) {
        *pn = c - '0';
        for(c = getch(); isdigit(c); c = getch())
            *pn = 10 * *pn + c - '0';
        *pn *= sign;
        if (c != EOF)
            ungetch(c);
        return c;
    } else {
        if(c != EOF)
            ungetch(c);
        ungetch(buf);
        return buf;
    }
}
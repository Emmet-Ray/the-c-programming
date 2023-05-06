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

int getfloat(double *pn);
int main(int argc, char const *argv[])
{
    double x;
    int status = getfloat(&x);
    printf("x : %f\n", x);
    printf("c : %c\n", status);
    return 0;
}

int getfloat(double *pn) {
    int c, sign;
    double power;
    while (isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    if(isdigit(c)) {
        *pn = c - '0';
        for(c = getch(); isdigit(c); c = getch())
            *pn = 10 * *pn + c - '0';
        if(c == '.')
            c = getch();
        for(power = 1.0; isdigit(c); c = getch()){
            *pn = 10.0 * *pn + c - '0';
            power *= 10;
        }

        *pn = sign * *pn / power;
        if (c != EOF)
            ungetch(c);
        return c;
    } else {
        if(c != EOF)
            ungetch(c);
        return 0;
    }
}
#include <stdio.h>

void rcomment(char c);
void in_comment();
int main(int argc, char const *argv[])
{
    int c;
    while((c = getchar()) != EOF) {
            rcomment(c);
    }   
    return 0;
}
void rcomment(char c) {
    char d;
    if(c == '/') {
       if((d = getchar()) == '*') {
            in_comment();
       } else if (d == '/') {
            putchar(c);
            rcomment(c);
       } else {
            putchar(c);
            putchar(d);
       }
    } else {
        putchar(c);
    }
}

void in_comment() {
    char c, d;
    c = getchar();
    d = getchar();
    while(c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}
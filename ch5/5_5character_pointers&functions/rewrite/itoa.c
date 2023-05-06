#include <stdio.h>
#include <string.h>
#define MAXLEN 100
void reverse(char *s);
void itoa(int n, char *s);

int main(int argc, char const *argv[])
{
    int n = -123456;
    char s[MAXLEN] = "hello, world";
    reverse(s);
    printf("%s\n", s);
    itoa(n ,s);
    printf("%s\n", s);
    reverse(s);
    printf("%s\n", s);
    return 0;
}



void reverse(char *s) {
    char *last = s + strlen(s) - 1;
    char temp;
    for(; s < last; s++, last--){
        temp = *s;
        *s = *last;
        *last = temp;
    }
}
void itoa(int n, char *s) {
    int sign;
    char *store = s; // remember the address of the head
    if ((sign = n) < 0){
        n = -n;
    }
    while(n) {
        *s++ = n % 10 + '0';
        n /= 10;
    }
    if (sign < 0) 
        *s++ = '-'; 
    *s = '\0';
    reverse(store);
}
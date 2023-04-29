#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
// naive implemention : convert a string of hexadecimal digits to its equivalent integer value
int htoi(char s[]);
//int atoi(char s[]);
int main(int argc, char const *argv[])
{
    char temp[] = "0xd5";
    printf("%d\n", htoi(temp));
    return 0;
}

int htoi(char s[]) {
    if(s[0] != '0' || (s[1] != 'x' && s[1] != 'X')) {
        printf("hexadecimal begin with 0x or 0X\n");
        exit(0);
    }

    int i,n;
    n = 0;
    for(i = 2;isdigit(s[i]) || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); i++) {
        if(isdigit(s[i])) {
            n = 16 * n + s[i] - '0';            // convert char to int
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + 10 + s[i] - 'a';
        } else {
            n = 16 * n + 10 + s[i] - 'A';
        }
    }
    return n;
}

/*
int atoi(char s[]) {
    int i, n;
    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + s[i] - '0';
    }
    return n;
}
*/
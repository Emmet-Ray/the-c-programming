#include <stdio.h>

//int itoa(char s[], int x);
void itoa(char s[], int x) {
    static int i;
    if(x/10) {
        itoa(s, x/10);
    } else {
        i = 0;
    }
    s[i++] = x % 10 + '0';
    s[i] = '\0';
}
int main(int argc, char const *argv[])
{
    char s[100];
    int x = 123456; 
    itoa(s, x);
    printf("%s", s);
    return 0;
}
/*
int itoa(char s[], int x) {
    if(x / 10) {
        int index = itoa(s, x/10);
        s[++index] = x % 10 + '0'; 
        s[index + 1] = '\0';
        return index;
    }
    else {
        s[0] = x % 10 + '0';
        return 0; 
    }
}
*/
#include <stdio.h>

int lower(char c) {
    return (c >= 'A' && c <= 'Z') ? ('a' + c - 'A') : c;
}
int main(int argc, char const *argv[])
{
    int n = 2;
    printf("%c %c\n",lower('a'), lower('A')); 
    printf("%d %d\n", ++n, n * 2);
    return 0;
}

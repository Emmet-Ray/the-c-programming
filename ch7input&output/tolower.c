#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int c;
    while((c = getchar()) != EOF)
        putchar(tolower(c));
    return 0;
}

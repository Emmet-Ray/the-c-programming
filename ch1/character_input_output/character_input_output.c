#include <stdio.h>

int main() {
    printf("EOF : %d\n", EOF); // To see the value of EOF
    printf("'a' != EOF : %d\n", 'a' != EOF);
    printf("EOF == EOF : %d\n", EOF != EOF);
    int c;
    while((c = getchar()) != EOF) { // EOF is Ctrl + z
            putchar(c);
    }
    return 0;
}
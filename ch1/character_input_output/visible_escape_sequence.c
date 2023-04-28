#include <stdio.h>

int main() {
    int c;
    while((c = getchar()) != EOF) { // EOF is Ctrl + z
        if(c == '\t') {
            putchar('\\');
            putchar('t');
            continue;
        }
        if(c == '\b') {
            putchar('\\');
            putchar('b');
            continue;
        }
        if(c == '\\'){
            putchar('\\');
            putchar('\\');
            continue;
        }
        putchar(c);
    }
    return 0;
}
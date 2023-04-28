#include <stdio.h>

// copy input into output and replace a string of one or more blanks by a single blank

int main() {
    int c = 0;
    char pre_c = EOF; 
    while((c = getchar()) != EOF) {
        /* my version
        if(c == '\t' || c == ' ') {
            while((c = getchar()) == '\t' || c == ' ') {
            }
            putchar(' ');
            putchar(c);
        }*/
        if(c == '\t' || c == ' ') {
            if(pre_c != '\t' && pre_c != ' ')
                putchar(c);
        }
        else 
            putchar(c);
        pre_c = c;
   }
}
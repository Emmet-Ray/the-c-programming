#include <stdio.h>
#define OUT 1
#define IN 0
// count lines, words, characters in input
int main() {
    int c, nl, nw, nc;
    int flag;
    nl = nw = nc = 0;
    flag = OUT; 
    while((c = getchar()) != EOF) { // EOF is Ctrl + z
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t'){
            flag = OUT;
        }
        else if(flag == OUT) {
            ++nw;
            flag = IN;
        } 
    }
    printf("lines : %d\t words : %d\t characters : %d\n", nl, nw, nc);
    return 0;
}
#include <stdio.h>

int main() {
    int c, nl, nb, nt, bs;
    // count blanks, tabs, newlines
    nl = nb = nt = bs = 0;
    while((c = getchar()) != EOF) { // EOF is Ctrl + z
        if(c == '\n')
            ++nl;
        if(c == ' ')
            ++nb;
        if(c == '\t')
            ++nt;
        if(c == '\b')
            ++bs;
    }
    printf("newlines : %d \t blanks : %d \t tabs : %d \t backspace : %d \n", nl, nb, nt, bs);
    return 0;
}
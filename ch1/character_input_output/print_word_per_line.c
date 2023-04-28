#include <stdio.h>
#define OUT 1
#define IN 0
// print word per line from input 
int main() {
    int c, pre_c;
    int flag;
    flag = OUT; 
    //pre_c = EOF;  do not need

    while((c = getchar()) != EOF) { // EOF is Ctrl + z
        if(c == ' ' || c == '\n' || c == '\t'){ // current c is blanks i.e. a word sperator
            if(flag = IN){ // answer : in word , do not need variable pre_c
            // if(pre_c != ' ' || pre_c != '\n' || pre_c != '\t' )  // and previous c is not blanks, then print newline           
                flag = OUT;                                           
                putchar('\n');                // i.e. finish a word                   // else do not need to print newline
            }
        }
        else if(flag == OUT) { // is not blanks and not in a word i.e. beginning a word
            flag = IN;
            putchar(c);
        } 
        else { // is not blanks and in a word i.e. inside a word
            putchar(c);
        }
       // pre_c = c;
    }
    return 0;
}
#include <stdio.h>
#define MAX_LENGTH 20
#define IN 1
#define OUT 0
int main() {
    int word_length[MAX_LENGTH];
    int c, word_index, state, length;
    c = word_index = state = length = 0;
    for(int i = 0;i < MAX_LENGTH; i++) {
        word_length[i] = 0;
    }

    // count length of each world and put in array word_length
    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\t' || c == '\n') {
            if(state = IN) { // finish counting a word, 
                state = OUT;
                word_length[word_index] = length;
                length = 0;
                word_index++;
            }
        } else if (state = OUT) { // begin count a word, length = 1
           length = 1; 
           state = IN;
        } else {  //inside a word, continue count
            ++length;
        }
    }
    /*
    if(length != 0) {
        word_length[word_index] = length;
        word_index++;
    }
    */ 
    // print horizontal histogram
    printf("\t word length horizontal histogram\n");
    for(int i = 0; i < word_index; i++) {
        for(int j = 0;j < word_length[i]; j++) {
            printf("-");
        }
        printf("%d\n", word_length[i]);
    }
}
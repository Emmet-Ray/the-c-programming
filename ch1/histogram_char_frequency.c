#include <stdio.h>
#define LENGTH 255
#define IN 1
#define OUT 0

// count character occurence frequencies, print horizontal hitogram
int main(int argc, char const *argv[])
{
    int char_frequency[LENGTH]; 
    char character[LENGTH];
    int c, array_index, state, index;
    c = array_index = state = index = 0;

    for(int i = 0; i < LENGTH; i++) {
        char_frequency[i] = 0;
    } 


    while((c = getchar()) != EOF) {
        state = OUT; 
        for(int i = 0; i < array_index; i++) {
            if(c == character[i]) {
                state = IN;
                index = i;
            }
       } 

       if(state == IN) { // c is in the array character[]
            char_frequency[index]++;
       } else {
            char_frequency[array_index++] = 1;
            character[array_index] = c;
       }
    }

    printf("\t character frenquency horizontal histogram\n");
    for(int i = 0; i < array_index; i++) {
        c = character[i];
        if(c == '\t') {
            printf("\\t:");
        } else if(c == '\n') {
            printf("\\n:");
        } else if (c == ' ') {
            printf("' ':");
        } else if (c == EOF) {
            printf("EOF:");
        } else {
            printf("%c:", c);
        }
        for(int j = 0;j < char_frequency[i]; j++) {
            printf("-");
        }
        printf("%d\n", char_frequency[i]);
    }
    return 0;
}

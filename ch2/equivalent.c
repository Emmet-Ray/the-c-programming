#include <stdio.h>
#define LENGTH 100
#define LIMIT 100
enum loop {NO,YES};
enum loop okloop = YES;
int main(int argc, char const *argv[])
{
    int i = 0, c = 0;
    char s[LENGTH]; 
    /*  
        equivalent version with && 
        
        for(;i < LIMIT - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
            s[i] = c;
        } 
    */ 
    while(okloop) {
        if(i >= LIMIT - 1) {
            okloop = NO;
        } else if ((c = getchar()) == '\n') {
            okloop = NO;
        } else if (c == EOF) {
            okloop = NO;
        } else {
            s[i++] = c;
        }
    }

    printf("s : %s\n", s);
    return 0;
}

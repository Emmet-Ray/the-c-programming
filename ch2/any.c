#include <stdio.h>
#define NOCHAR -1
int any(char s1[], char s2[]);
int main(int argc, char const *argv[])
{
    char s1[] = "hello, world!";    
    char s2[] = "hello";
    int p = any(s1, s2);
    printf("%d\n", p); // should be 0
    return 0;
}

int any(char s1[], char s2[]) {
    int i, j;
    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s1[i+j] == s2[j] && s2[j] != '\0'; j++) {
        }
        if(s2[j] == '\0')
            return i;
    }
    
    return NOCHAR;
}
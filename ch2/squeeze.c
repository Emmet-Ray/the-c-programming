#include <stdio.h>

enum NOT_IN{IN, OUT};
// delete each char in s1 that matches any char in s2
void squeeze(char s1[], char s2[]);
// helper function, c in s or not
int not_in(char s[], char c);
int main(int argc, char const *argv[])
{
    char s1[] = "hello, world!";    
    char s2[] = "lo";
     
    printf("%s\n", s1);
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j;

    for(i = j = 0; s1[i] != '\0';i++) {
        if(not_in(s2, s1[i])) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int not_in(char s[], char c) {
    for(int i = 0; s[i] != '\0'; i++) {
        if(c == s[i]) 
            return IN;
    }
    return OUT;
}
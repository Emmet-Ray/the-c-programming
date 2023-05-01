#include <stdio.h>

void escape(char s[], char t[]);
int main(int argc, char const *argv[])
{
    char s[] = "hello,\tworld!\n"; 
    char t[256];
    escape(s,t);
    printf("t : %s\n", t);
    return 0;
}

void escape(char s[], char t[]) {
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        default:
            t[j++] = s[i];
            break;
        }
    }
    t[j] = '\0';
}
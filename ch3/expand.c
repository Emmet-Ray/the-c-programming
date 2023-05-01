#include<stdio.h>
#include <ctype.h>
#include <string.h>
void expand(char s1[], char s2[]);
void expand_answer(char s1[], char s2[]);
int main(int argc, char const *argv[])
{
    char s1[256] = "a-b-ca-z0-9A-zA-Z--";
    char s2[256];    
    expand_answer(s1, s2);
    printf("s2 : %s\n", s2);
    //char a[2] = "-a";
    //printf("%d %d\n", isalpha(a[0]), isalpha(a[1]));
    return 0;
}

void expand(char s1[], char s2[]) {
    int j, i;
    i = j = 0;
    for(; s1[i] != '\0'; i++) {
        if(isalpha(s1[i])) {
            if(s1[i+1] == '-') {
                if(isalpha(s1[i+2])) {
                    char start = tolower(s1[i]);
                    char end = tolower(s1[i+2]);
                    int offset = end - start + 1;
                    for(int l = 0; l < offset; l++) {
                        s2[j++] = start + l;
                    }
                    i += 2;
                }
                else {
                    s2[j++] = s1[i];
                }
            } else {
                s2[j++] = s1[i];
            } 
        } 
        else if (isdigit(s1[i])) {

            if(s1[i+1] == '-') {
                if(isdigit(s1[i+2])) {
                    char start = tolower(s1[i]);
                    char end = tolower(s1[i+2]);
                    int offset = end - start + 1;
                    for(int l = 0; l < offset; l++) {
                        s2[j++] = start + l;
                    }
                    i += 2;
                } else {
                    s2[j++] = s1[i];
                }
            } else {
                s2[j++] = s1[i];
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

void expand_answer(char s1[], char s2[]) {
    int i,j;
    i = j = 0;
    char c;
    while((c = s1[i++]) != '\0') {
        if(s1[i] == '-' && s1[i+1] >c) {
            i++;
            while(c <= s1[i]) {
                s2[j++] = c++;
            }
        } else {
            s2[j++] = c;
        }
    }
}
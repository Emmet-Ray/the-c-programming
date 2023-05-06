#include <stdio.h>

void my_strcpy(char *s, char *t);
int my_strcmp(char *s, char *t);
void my_strcat(char *s, char *t);
int my_strend(char *s, char *t);

void my_strncpy(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int main(int argc, char const *argv[])
{
    // my_strcat
    char s1[] = "hello, ";
    char s2[] = "world!\n";
    my_strcat(s1, s2);
    printf("%s", s1);

    // my_strend
    char s3[] = "hello";
    char s4[] = "llo, ";
    char s5[] = "ello";
    printf("s4 ends s3 : %s \ns5 ends s3 : %s\n", (my_strend(s3, s4)) ? "true" : "false", (my_strend(s3, s5)) ? "true" : "false");

    // my_strncpy
    char s6[] = "hello";
    char s7[] = "llo, ";
    my_strncpy(s6, s7, 4);
    printf("%s\n", s6); 
    my_strncpy(s6, s7, 3);
    printf("%s\n", s6); 

    // my_strncmp
    char s8[] = "hello";
    char s9[] = "hell";
    printf("%d\n", my_strncmp(s8, s9, 4));
    printf("%d\n", my_strncmp(s8, s9, 5));
    printf("%d\n", my_strncmp(s8, s9, 6));
    return 0;
}

void my_strcpy(char *s, char *t) {
    while(*s++ = *t++)
        ;
}
int my_strcmp(char *s, char *t) {
    for(;*s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}
void my_strcat(char *s, char *t) {
    while(*s) // s != '\0'
        s++;
    while(*s++ = *t++) // strcpy
        ;
}
int my_strend(char *s, char *t) {
    char *temp, *copy;
    for(; *s != '\0'; s++) {
        temp = s;
        copy = t;
        for(;*temp == *copy; temp++, copy++) {
            if (*temp =='\0')
                return 1;
        }
    }
    return 0;
}
void my_strncpy(char *s, char *t, int n) {
    int i = 0;
    for(;  t[i] != '\0' && i < n; i++) {
        s[i] = t[i];
    }
    s[i] = '\0';
}
int my_strncmp(char *s, char *t, int n) {
    int i = 0;
    for(; s[i] == t[i] && i < n; i++)
        if(s[i] == t[i])
            return 0;
    return s[i] - t[i];
}
void my_strncat(char *s, char *t, int n);
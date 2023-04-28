#include <stdio.h>
#define MAXLENGTH 1000
#define COMMENT 1
#define NOTCOMMENT 0

//read one line, return length 
int getline(char line[], int limit);
// judge have // or not
int one_line_comment(char line[], int len);
int begin_many_line_comment(char line[], int len);
int end_many_line_comment(char line[], int len);
/*
    read one line, process one line

*/
int main(int argc, char const *argv[])
{
    int len;
    int temp;
    char line[MAXLENGTH];
    while((len = getline(line, MAXLENGTH)) > 0) {
        if((temp = one_line_comment(line, len)) == COMMENT) {
            continue;
        }
        if(begin_many_line_comment(line, len) == COMMENT) {
            while(1) {
                len = getline(line, MAXLENGTH);
                if(end_many_line_comment(line, len) == COMMENT)
                    break;
            }
            continue;
        }
        printf("len : %d \t %s", len, line); 
    }
   return 0;
}
int getline(char line[], int limit) {
    int c, i;

    for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
            line[i] = c;
    }

    if(c == '\n') 
        line[i++] = '\n';
    line[i] = '\0';

    return i;
}
int one_line_comment(char line[], int len) {
    for(int i = 0; i + 1 < len; i++) {
        if(line[i] == '/') {
            if(line[i + 1] == '/'){
                return COMMENT;
            }
        }
    }
    return NOTCOMMENT;
}
int begin_many_line_comment(char line[], int len) {
    for(int i = 0; i + 1 < len; i++) {
        if(line[i] == '/') {
            if(line[i + 1] == '*'){
                return COMMENT;
            }
        }
    }
    return NOTCOMMENT;
}
int end_many_line_comment(char line[], int len) {
    for(int i = 0; i + 1 < len; i++) {
        if(line[i] == '*') {
            if(line[i + 1] == '/'){
                return COMMENT;
            }
        }
    }
    return NOTCOMMENT;
}
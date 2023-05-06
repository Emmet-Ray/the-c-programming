#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 1000 // max size of one line
#define MAXLINES 5000 // size of pointers array 
#define MAXSTORE 5000  // size of lines array
// pointer arrays
/*
    read text lines
    sort text lines
    write text lines

    data structure : 
        text lines stored in an character array
        pointers to text lines stored in an array (pointer array)
*/

char *lineptr[MAXLINES];

int getline(char *, int);
void swap(void *v[], int i, int j);
/// @brief 
/// @param lineptr pointers array
/// @param line_store lines array
/// @param maxlines max lines to read 
/// @return  too many return -1, else return total lines read
int readlines(char *lineptr[], char *line_store, int maxlines);
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decreasing);

int numcmp(char *s1, char *s2);

int main(int argc, char const *argv[])
{
    int numeric, decreasing, fold;
    numeric = 0;
    decreasing = 0;
    fold = 0;

    for(int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) 
            numeric = 1;
        else if (strcmp(argv[i], "-r") == 0)
            decreasing = 1;
        else if (strcmp(argv[i], "-f") == 0)
            fold = 1;
    }
    int nlines; //read how many lines ?
    char line_store[MAXSTORE];
    if((nlines = readlines(lineptr, line_store, MAXLINES)) >= 0) {
        
        myqsort(lineptr, 0, nlines - 1, (numeric == 1) ? numcmp : strcmp);
        writelines(lineptr, nlines, decreasing);
        return 0;
    } else {
        printf("too many lines\n");
        return 1;
    }
}

int getline(char *line, int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    if (c == '\n') {
        line[i++] = '\n';
    }

    line[i] = '\0';
    return i;
    
}
void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int readlines(char *lineptr[], char *line_store, int maxlines) {
    int len;
    int nlines = 0; // return value
    char line[MAXLEN];
    char *p = line_store; // index for line_store
    while((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= MAXLINES || p + len > line_store + MAXSTORE) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }

    return nlines;
}
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    if (left >= right)
        return;

    int i, last;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
  }

    swap(v, left, last);
    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}
void writelines(char *lineptr[], int nlines, int decreasing) {
    if (decreasing) {
        for(int i = nlines - 1; i >= 0 ; i--) {
            printf("%s\n", lineptr[i]);
        }
    } else {
        for(int i = 0; i < nlines; i++) {
            printf("%s\n", lineptr[i]);
        }
    }

}
int numcmp(char *s1, char *s2) {
    double value1 = atof(s1), value2 = atof(s2);
    if (value1 < value2)
        return -1;
    else if (value1 > value2)
        return 1;
    else 
        return 0;
}
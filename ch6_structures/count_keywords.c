#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS sizeof(keytab) / sizeof(keytab[0])
#define BUFSIZE 100
struct key {
    char *word;
    int count;
} keytab[] = {
    "break", 0,
    "char", 0,
    "double", 0,
    "float", 0,
    "if", 0,
    "int", 0,
    "return", 0,
    "while", 0 
};
char buf[BUFSIZE];
int bufp = 0;

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);
//int binsearch(char *, struct key *, int);
int getch(void);
void ungetch(int);


int main(int argc, char const *argv[])
{
    int n;
    char word[100];
    struct key *p;
    while(getword(word, MAXWORD) != EOF) 
        if (isalpha(word[0]))
            // write as n = binsearch(word, keytab, NKEYS) >= 0, the precedence of >= is higher than =, so n = 1 or 0
            if ((p = binsearch(word, keytab, NKEYS)) != NULL) 
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++) 
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

int getword(char *word, int limit) {
    int c;
    char *w = word; // pointer to word
    while(isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for ( ; --limit > 0; w++) 
        if (!isalnum(*w = getch())) {
            ungetch(*w); // wrote as ungetch(c), waste almost 1.5h
            break;
        }
    *w = '\0';
    return word[0];
}
struct key * binsearch(char *word, struct key *tab, int nkeys) {
    int condition; // use condition to record the result to reduce repetition
    struct key *low, *high, *middle;
    low = tab;
    high = tab + nkeys;

    while (low <= high) {
        middle = low + (high - low)/2;
        if ((condition = strcmp(word, middle->word)) == 0) 
            return middle;
        else if (condition < 0)
            high = middle - 1;
        else 
            low = middle + 1;
    }
    return NULL;
}
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int x) {
    if (bufp < BUFSIZE) 
        buf[bufp++] = x;
    else 
        printf("ungetch: too many characters\n");
}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXWORD 100

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

char buf[BUFSIZE];
int bufp = 0;

int getword(char *word, int limit);
int getch(void);
void ungetch(int);
struct tnode *addtree(struct tnode *root, char *word);
void printtree(struct tnode *root);
struct tnode *talloc();
char *string_alloc(char *s);

int main(int argc, char const *argv[])
{
    char word[MAXWORD];
    struct tnode *root = NULL;
    while(getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word);
    }
    printtree(root);
    return 0;
}

struct tnode *addtree(struct tnode *root, char *word) {
    int condition;
    if (root == NULL) {
        root = talloc();
        root->word = string_alloc(word);
        root->count = 1;
        root->left = NULL;
        root->right = NULL;
    } else if ((condition = strcmp(word, root->word)) == 0) {
        root->count++;
    } else if (condition < 0) {
        root->left = addtree(root->left, word);
    } else {
        root->right = addtree(root->right, word);
    }
    return root;
}
void printtree(struct tnode *root) {
    if(root) {
        printtree(root->left);
        printf("%4d %s\n", root->count, root->word);
        printtree(root->right);
    }
}
struct tnode *talloc() {
    return (struct tnode *)malloc(sizeof(struct tnode));
}
char *string_alloc(char *s) {
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
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
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int x) {
    if (bufp < BUFSIZE) 
        buf[bufp++] = x;
    else 
        printf("ungetch: too many characters\n");
}
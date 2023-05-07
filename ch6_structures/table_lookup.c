#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];


unsigned hash(char *);
struct nlist *lookup(char *name);
struct nlist *install(char *name, char *defn);
char *string_alloc(char *s); 
int main(int argc, char const *argv[])
{
    install("while", "loop");
    printf("%s %s", lookup("while")->name, lookup("while")->defn); 
    return 0;
}

unsigned hash(char *s) {
    unsigned value;
    for (value = 0; *s != '\0'; s++)
        value = *s +31 * value; 
    return value % HASHSIZE;
}
struct nlist *lookup(char *name) {
    struct nlist *np;
    for (np = hashtab[hash(name)]; np != NULL; np = np->next) 
        if (strcmp(np->name, name) == 0) {
            return np;
        }
    return NULL;
}
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    if (lookup(name) == NULL) {
        np = (struct nlist *)malloc(sizeof(struct nlist));
        np->name = string_alloc(name);
        if (np == NULL || np->name == NULL)
            return NULL;
        np->next = NULL;
        hashtab[hash(name)] = np;
    } else {
        free(np->defn);
    }
    if ((np->defn = string_alloc(defn)) == NULL)
        return NULL;
    return np;
}
char *string_alloc(char *s) {
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}
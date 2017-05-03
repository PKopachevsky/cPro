#include <stdlib.h>
#include <memory.h>
#include "hash.h"
#include "lookup.h"

static struct nlist *hashtab[HASHSIZE];

struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np->next) {
        if(strcmp(s, np -> name) == 0)
            return np;
    }
}


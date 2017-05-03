#ifndef CPRO_LOOKUP_H
#define CPRO_LOOKUP_H

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist *lookup(char *s);

#endif //CPRO_LOOKUP_H

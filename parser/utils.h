//
// Created by pavel on 04.05.17.
//

#ifndef CPRO_UTILS_H
#define CPRO_UTILS_H

struct WordNode {
    char *word;
    struct WordNode * next;
};


struct WordNode *nalloc(void);

#endif //CPRO_UTILS_H

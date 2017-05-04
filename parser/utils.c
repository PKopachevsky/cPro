#include <stdlib.h>
#include "utils.h"

struct WordNode *nalloc(void) {
    struct WordNode *node = (struct WordNode *) malloc(sizeof(struct WordNode));
    node->word = malloc(64 * sizeof(char));
    node->next = NULL;
    return node;
}

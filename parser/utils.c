#include <stdlib.h>
#include "utils.h"

struct WordNode *walloc(void) {
    struct WordNode *node = (struct WordNode *) malloc(sizeof(struct WordNode));
    node->word = malloc(64 * sizeof(char));
    node->next = NULL;
    return node;
}

struct TreeNode *talloc(void) {
    struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    for (char i = 0; i < 26; i++) {
        node->nodes[i] = NULL;
    }
    return node;
}

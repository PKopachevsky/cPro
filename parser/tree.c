#include <stdio.h>
#include <string.h>
#include "utils.h"

struct TreeNode *toTree(struct WordNode *wnode) {
    char *word, c;
    struct TreeNode *root = talloc();
    struct TreeNode *tnode, *node;
    while (wnode != NULL) {
        word = wnode->word;
        tnode = root;
        while ((c = *word++) != '\0') {
            node = tnode->nodes[c - 'a'];
            if (node == NULL) {
                node = talloc();
                tnode->nodes[c - 'a'] = node;
            }
            tnode = node;
        }
        if (node->count++ == 0) {
            node->word = strdup(wnode->word);
        }
        wnode = wnode->next;
    }
    return root;
}

void tprint(struct TreeNode *node, int *counter) {
    if (node->count > 0) {
        (*counter)++;
        printf("%s : %d\n", node->word, node->count);
    }
    struct TreeNode *pNode;
    for (char i = 0; i < 26; i++) {
        pNode = node->nodes[i];
        if (pNode != NULL) {
            tprint(pNode, counter);
        }
    }
}
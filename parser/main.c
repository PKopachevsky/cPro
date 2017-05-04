#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "parser.h"
#include "tree.h"

void main() {
    FILE *fp = fopen("./test.txt", "r");

    if (fp == NULL) {
        printf("File not found !!");
        return;
    }
    struct WordNode *node = toList(fp);
    struct TreeNode *treeRoot = toTree(node);
    int counter = 0;
    tprint(treeRoot, &counter);

    printf("Total count: %d", counter);
}
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "parser.h"

void main() {
    FILE *fp = fopen("./test.txt", "r");

    if (fp == NULL) {
        printf("File not found !!");
        return;
    }

    struct WordNode *node = parse(fp);
    while (node != NULL) {
        printf("%s ", node->word);
        node = node->next;
    }
}
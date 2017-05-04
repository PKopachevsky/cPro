#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void main() {
    FILE *fp = fopen("./test.txt", "r");

    if (fp == NULL) {
        printf("File not found !!");
        return;
    }
    char c, cp = 0;
    struct WordNode *node = nalloc();
    struct WordNode *next;
    char *word = node->word;
    while ((c = (char) fgetc(fp)) != EOF) {
        switch (c) {
            case ' ':
            case '.':
            case ',':
            case '!':
            case '?':
            case ':':
            case '\n':
            case '\t':
                if (word != node->word) {
                    *word = '\0';
                    next = node;
                    node = nalloc();
                    node->next = next;
                    word = node->word;
                }
                break;
            default:
                *word++ = c;
        }
    }
    while (node != NULL) {
        printf("%s ", node->word);
        node = node->next;
    }

}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

struct WordNode *parse(FILE *fp){

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
            case '\\':
            case '/':
            case '(':
            case ')':
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
                if (word == node->word && c >= '0' && c <= '9') {
                    break;
                }
                *word++ = (char) tolower(c);
        }
    }
    return node;
}

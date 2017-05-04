#include <stdio.h>
#include <ctype.h>
#include "utils.h"

struct WordNode *toList(FILE *fp) {
    char c;
    struct WordNode *node = walloc();
    struct WordNode *next;
    char *word = node->word;
    while ((c = (char) fgetc(fp)) != EOF) {
        c = (char) tolower(c);
        if (c >= 'a' && c <= 'z' || c == '\'') {
            if (c != '\'') {
                *word++ = (char) tolower(c);
            }
        } else if (word != node->word) {
            *word = '\0';
            next = node;
            node = walloc();
            node->next = next;
            word = node->word;
        }
    }
    return node;
}

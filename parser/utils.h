//
// Created by pavel on 04.05.17.
//

#ifndef CPRO_UTILS_H
#define CPRO_UTILS_H

struct TreeNode {
    int count;
    char *word;
    struct TreeNode *nodes[26];
};

struct WordNode {
    char *word;
    struct WordNode * next;
};


struct WordNode *walloc(void);
struct TreeNode *talloc(void);

#endif //CPRO_UTILS_H

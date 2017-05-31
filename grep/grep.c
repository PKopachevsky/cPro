#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

FILE *fileopen(char *path, char *mode);

int main(int argc, char **argv) {

    FILE *src;

    if (argc < 2) {
        exit(1);
    }

    char *patter = *++argv;
    char p_len = strlen(patter);

    if (argc > 2) {
        src = fileopen(*++argv, "r");
    } else {
        src = stdin;
    }

    char buff[1024];
    int i = 0, pi = 0;
    char c;
    char *p = patter;
    while ((c = (char) getc(src)) != EOF) {
        if (c == *p) {
            p++;
            if (++pi >= p_len) {
                buff[i] = '\0';
                printf("%s",buff);
                do {
                    putchar(c);
                    c = (char) getc(src);
                } while (c != EOF && c != '\n');
            }
        } else {
            p = patter;
            pi = 0;
        }
        if (c == '\n') {
            i = 0;
        } else {
            buff[i++] = c;
        }
    }
    return 0;
}

FILE *fileopen(char *path, char *mode) {
    FILE *fp;
    if ((fp = fopen(path, mode)) == NULL) {
        fprintf(stderr, "Failed to open file %s\n", path);
        exit(1);
    }
    return fp;

}
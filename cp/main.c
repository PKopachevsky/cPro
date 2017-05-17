#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    FILE *srcFile = stdin, *dstFile = stdout;

    FILE *fileopen(char *, char *);
    void filecopy(FILE *, FILE *);

        if (argc >= 2) {
        srcFile = fileopen(*++argv, "r");
    }
    if (argc >= 3) {
        dstFile = fileopen(*++argv, "w");
    }
    filecopy(srcFile, dstFile);
}

FILE *fileopen(char *path, char *mode) {
    FILE *fp;
    if ((fp = fopen(path, mode)) == NULL) {
        fprintf(stderr, "Failed to open file %s\n", path);
        exit(1);
    }
    return fp;

}

void filecopy(FILE *src, FILE *dst) {
    int c;

    while ((c = getc(src)) != EOF) {
        putc(c, dst);
    }
}
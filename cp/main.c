#include <stdio.h>

void main(int argc, char *argv[]) {
    FILE *srcFile = stdin, *dstFile = stdout;

    void filecopy(FILE *, FILE *);

    if (argc >= 2) {
        srcFile = fopen(*++argv, "r");
    }
    if (argc >= 3) {
        dstFile = fopen(*++argv, "w");
    }
    filecopy(srcFile, dstFile);
}

void filecopy(FILE *src, FILE *dst) {
    int c;

    while ((c = getc(src)) != EOF) {
        putc(c, dst);
    }
}
#include <stdio.h>

void main() {
    FILE *fp;

    fp = fopen("/tmp/test.txt", "w+");
    fprintf(fp, "This is testing for printf...\n" );
    fputs("This is testing for fputs\n", fp);
    fclose(fp);
}
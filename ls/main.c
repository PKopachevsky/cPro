#include <stdio.h>
#include "fsize.h"

void main(int argc, char **argv) {
    char *name;
    if (argc > 1) {
        name = *++argv;
    } else {
        name = ".";
    }
    long byteSize = fsize(name);
    printf("%8.2f MB  %s\n", (double) (byteSize / (1024 * 1024)), name);
}

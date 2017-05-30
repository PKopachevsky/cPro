#include <stdio.h>
#include <fcntl.h>

#define _READ = 0444
#define _WRITE = 0222

static FILE _iob[FOPEN_MAX] = {
        { 0 },
        { 0 },
        { 0 },
};

FILE fileopen2(char *name, char *mode) {
    int fd;
}


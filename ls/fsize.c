#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#define MAX_PATH 1024

typedef struct dirent Dirent;

long int visitDir(char *, long int (*fcn)(char *));

long int fsize(char *name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return 0;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
        return visitDir(name, fsize);
    } else {
        return stbuf.st_size;
    }
}

long int visitDir(char *dir, long int (*fcn)(char *)) {
    char name[MAX_PATH];
    DIR *dfd;
    Dirent *dp;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "visirDir: can't open %s\n", dir);
        return 0;
    }
    int summ = 0;
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        if (strlen(dir) + strlen((dp->d_name) + 2) > MAX_PATH) {
            continue;
        } else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            summ += (*fcn)(name);
        }
    }
    closedir(dfd);
    return summ;
}
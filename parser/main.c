#include <stdio.h>
void main(){
    FILE *fp;

    fp = fopen("/tmp/test.txt", "r");
    char buff[255];
    fgets(buff, 255, (FILE*)fp);
    printf(buff);
}
#include <stdio.h>

#define STEP 250

void main(){
    int c, i, j;
    int n = 'Z' - 'A' + 1;
    int countArr[n];
    for(i = 0; i < n; ++i){
        countArr[i] = 0;
    }
    while((c = getchar()) != EOF){
        if (c >= 'A' && c <= 'Z'){
            ++countArr[c - 'A'];
        }
        if (c >= 'a' && c <= 'z'){
            ++countArr[c - 'a'];
        }
    }
    for(i = 0; i < n; ++i){
        putchar('A' + i);
        c = countArr[i];
        printf(" : ");
        for(j = 0; j <= c; j+=250 ){
            putchar('#');
        }
        putchar('\n');
    }
}
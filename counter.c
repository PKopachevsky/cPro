#include <stdio.h>

void count(int buff[]){
     int c;
     while((c = getchar()) != EOF){
        if (c >= 'A' && c <= 'Z'){
            ++buff[c - 'A'];
        }
        if (c >= 'a' && c <= 'z'){
            ++buff[c - 'a'];
        }
    }
}
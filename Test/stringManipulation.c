#include <stdio.h>

typedef struct key {
    char encryption[16];
    struct Key* next;
} Key;


int main() {
    char* p = "hello";
    printf("%c\n",p[1]);
    printf("%c\n",*(p+1));
    return 0;
}
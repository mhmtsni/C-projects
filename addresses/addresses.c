#include <stdio.h>
int main(void) {
    char *s = "Hi!";
    printf("%p", s);
    printf("%p", (s + 1));
    printf("%p\n", (s + 2));



}
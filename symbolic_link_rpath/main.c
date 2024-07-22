#include <stdio.h>

extern void foo();

int main() {
    printf("About to run foo:\n");
    foo();
    return 0;
}

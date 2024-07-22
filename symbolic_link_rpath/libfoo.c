#include <stdio.h>

#if !defined(FOO_IDENTIFIER)
#define FOO_IDENTIFIER "default"
#endif

void foo() {
    printf("Foo called with identifier '%s'!\n", FOO_IDENTIFIER);
}

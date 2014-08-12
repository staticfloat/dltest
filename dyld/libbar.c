#include <stdio.h>

// This to be found later
void foo(void);

void bar(void)
{
	printf("bar, pre-foo!\n");
	foo();
	printf("bar, post-foo!\n");
}

#include <stdio.h>

void bar(void);

int main(void) {
	printf("main, pre-bar!\n");
	bar();
	printf("main, post-bar!\n");
	return 0;
}

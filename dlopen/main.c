#include <stdio.h>
#include <dlfcn.h>

void bar(void);

int main(void) {
    // Have main look for libfoo (will fail because main does not have correct rpath)
	void * libfoo = dlopen("libfoo.dylib", RTLD_NOW);
    if( libfoo != NULL ) {
        printf("main: Found libfoo!\n");
        void * foo = dlsym(libfoo, "foo");
        if( foo != NULL ) {
            printf("main: Found foo()!\n");
            void (*foo_fcn)() = foo;
            foo_fcn();
        }
    } else {
        printf("main: Couldn't find libfoo. :(\n");
    }

    // Have libbar look for libfoo (will succeed, because libbar has correct rpath)
	printf("main: pre-bar!\n");
	bar();
	printf("main: post-bar!\n");

	return 0;
}

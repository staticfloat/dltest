#include <stdio.h>
#include <dlfcn.h>

void bar(void)
{
	void * libfoo = dlopen("libfoo.dylib", RTLD_NOW);
	if( libfoo != NULL ) {
		printf("libbar: Found libfoo!\n");
		void * foo = dlsym(libfoo, "foo");
		if( foo != NULL ) {
			printf("libbar: Found foo()!\n");
			void (*foo_fcn)() = foo;
			foo_fcn();
		}
	} else {
		printf("libbar: Couldn't find libfoo. :(\n");
	}
}

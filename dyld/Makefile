all:
	gcc -shared -o libfoo/libfoo.dylib libfoo/libfoo.c
	install_name_tool -id @rpath/libfoo.dylib libfoo/libfoo.dylib
	gcc -shared -o libbar.dylib -Llibfoo/ -lfoo -Wl,-rpath,@executable_path/libfoo libbar.c
	gcc -o main -L. -lbar main.c

clean:
	rm -f libfoo/*.dylib *.dylib main

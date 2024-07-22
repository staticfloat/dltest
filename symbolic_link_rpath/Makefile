all: simple

ifeq ($(shell uname -s), Linux)
shlib_ext = so
RPATH_ORIGIN = -Wl,-rpath,'$$ORIGIN' -Wl,-z,origin -Wl,--enable-new-dtags
define install_name_flags
endef
else
shlib_ext = dylib
RPATH_ORIGIN = -Wl,-rpath,'@loader_path/'
define install_name_flags
-install_name @rpath/$1
endef
endif

build/libfoo.$(shlib_ext): libfoo.c
	@mkdir -p build
	$(CC) -o $@ -shared -fPIC $(call install_name_flags,libfoo.$(shlib_ext)) libfoo.c
LIBFOO := build/libfoo.$(shlib_ext)

build/main: main.c build/libfoo.$(shlib_ext)
	@mkdir -p build
	$(CC) -o $@ main.c $(RPATH_ORIGIN) -Lbuild -lfoo
MAIN := build/main

simple: $(LIBFOO) $(MAIN)
	@mkdir -p build/simple
	cp $(LIBFOO) build/simple/$(notdir $(LIBFOO))
	cp $(MAIN) build/simple/main
	@build/simple/main

symlinked: $(LIBFOO) $(MAIN)
	@mkdir -p build/symlinked/libfoo_install_location build/symlinked/main_install_location
	@# Install `libfoo.so` and `main` into different directories, then symlink them into a shared directory
	cp $(LIBFOO) build/symlinked/libfoo_install_location/$(notdir $(LIBFOO))
	cp $(MAIN) build/symlinked/main_install_location/main
	ln -sf main_install_location/main build/symlinked/main
	ln -sf libfoo_install_location/$(notdir $(LIBFOO)) build/symlinked/$(notdir $(LIBFOO))
	build/symlinked/main

hardlinked: $(LIBFOO) $(MAIN)
	@mkdir -p build/hardlinked/libfoo_install_location build/hardlinked/main_install_location
	@# Install `libfoo.so` and `main` into different directories, then hardlink them into a shared directory
	cp $(LIBFOO) build/hardlinked/libfoo_install_location/$(notdir $(LIBFOO))
	cp $(MAIN) build/hardlinked/main_install_location/main
	ln -f build/hardlinked/main_install_location/main build/hardlinked/main
	ln -f build/hardlinked/libfoo_install_location/$(notdir $(LIBFOO)) build/hardlinked/$(notdir $(LIBFOO))
	build/hardlinked/main

clean:
	rm -rf build

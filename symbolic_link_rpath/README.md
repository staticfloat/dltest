# RPATH ignores symbolic links

This repository is used to show that you cannot symlink an executable and a library into a directory together and expect RPATH to find that library; the RPATH lookup is always with reference to the absolute path of the executable.
You _can_ put a symlink next to the executable itself, but this is useless if you want to have the flexibility to load different libraries with the same executable, as you can only have a single symlink next to it at once.

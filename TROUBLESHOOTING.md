# ldconfig Issue
If you see below message at your first time using assemblyline:  
` error while loading shared libraries: libassemblyline.so.1: cannot open shared object file: No such file or directory`  
please run `$ sudo ldconfig` to update the shared library cache.


# Old CC versions
We use the `__attribute__((deprecated("TEXt")))` in `assemblyline.{c,h}`. GCC >= `4.6.4` and Clang >= `3.4.1` support that.


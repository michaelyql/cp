## General Info
- **Include path** is the place to locate **header** files for the preprocessor to search for `#include` directives. Use `-I<dir>`
- `-L` is the location to search for library directories, for linking during build time.
- `-l` is to use the specific library. For example, files ending in `.so` (shared object) or `.a` (archive). When writing their name, you don't have to include the `.so` or `.a` as it will be inserted by the compiler.
- `-rpath` is the **runtime** search path that is stored in the executable and passed to the runtime linker to find shared objects at runtime.
- `.o` (object) files are 'static' library files linked during build time
- `.so` files are 'dynamic'/shared libraries linked during runtime
- `.a` (archive) files (`.lib` on Windows) are a collection of static object files 


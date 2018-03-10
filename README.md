# Modern OpenGL
The purpose of this library is to expose the OpenGL API using modern C++ classes. The API will be divided into the following concerns:

* Primitives - At its core, mogl will expose a simplified interface to the OpenGL API using enums classes, namespaces, overloaded functions and STL classes. These methods should have little or runtime overhead.
* RAII - Proper OpenGL use requires careful management of scopes and resource lifetimes. Using C++ RAII concepts, mogl will provide classes for managing these resources. Classes with names ending in "scope" will call the appropriate "bind" and "unbind" functions. Classes with names ending in "context" will provide `using` functions accepting `std::function` to control the OpenGL state machine.
* Objects - Several classes will be provided by mogl in an attempt to organize the primitive functions. These will be more opinionated and may be too restrictive for some scenarios.

## Usage
This is a header-only library. You can copy the source code into your project directly or add it to your includes path. To start using it, you can simply `#include <mogl.hpp>` and it will include the entire project. Alternatively, you can `#include` only the files you need.

Before `#include`-ing mogl files, you must `#include` an OpenGL loading library such as [glew](https://glew.sourceforge.net/) or [glad](https://github.com/Dav1dde/glad). For example:

```c++
#include <glad/glad.h>
#include <mogl.hpp>
```

## License
For now, this project will be unlicensed until I get far enough along that it serves a useful purpose. Assume that the license will be free an unencumbered, available to the public domain at large.
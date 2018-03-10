# Modern OpenGL
The purpose of this library is to expose the OpenGL API using modern C++ classes. The API is divided into the following concerns:

* Primitives - At its core, mogl will expose a simplified interface to the OpenGL API using enums, namespaces, overloaded functions and the STL. These methods will be inlined, where possible, and have little or no runtime overhead.
* RAII - Proper OpenGL use requires careful management of scopes and resource lifetimes. Using C++ RAII concepts, mogl will provide classes for managing these resources. Classes with names ending in "scope" will call the appropriate "bind" and "unbind" functions. Classes with names ending in "context" will provide `use` functions accepting `std::function` to control the active objects in the OpenGL state machine.
* Objects - Several classes will be provided by mogl in an attempt to encapsulate and organize primitive data and functions. These will be more opinionated and may be too restrictive for some scenarios.

## Development Status
*Very much still in an experimental status - Use at your own peril!!!*

## Usage
This is a header-only library. You can copy the source code into your project directly or add it to your include path. To start using it, you can simply `#include <mogl.hpp>` and it will include the entire project. Alternatively, you can `#include` only the files you need.

Before `#include`-ing mogl files, you must `#include` an OpenGL loading library such as [glew](https://glew.sourceforge.net/) or [glad](https://github.com/Dav1dde/glad). For example:

```c++
#include <glad/glad.h>
#include <mogl.hpp>
```

## License
For now, this project will be unlicensed until I get far enough along that it serves a useful purpose. Assume that the license will be free an unencumbered, available to the public domain at large.
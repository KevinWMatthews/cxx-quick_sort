# Quick Sort

A naive implementation of the Quick Sort algorithm.


## Background

This is a hands-on approach to learning. Don't just read about it; do it.


## Prerequisites

  * CMake 3.5.1
  * g++
  * gtest


## Setup

An out-of-tree build is recommended and is simple to do with CMake:
```bash
$ mkdir quick_sort && cd quick_sort
$ git clone https://github.com/KevinWMatthews/cxx-quick_sort
$ mkdir build_quick_sort_release build_quick_sort_debug
```

For release builds,
```bash
$ cd quick_sort/build_quick_sort_release
$ cmake ../quick_sort -DCMAKE_BUILD_TYPE=Release
```

For debug builds,
```bash
$ cd quick_sort/build_quick_sort_debug
$ cmake ../quick_sort -DCMAKE_BUILD_TYPE=Debug
```

## Build

```bash
$ cd quick_sort/build_quick_sort_<build_type>
$ make
```


## Tests

Unit tests can be compiled or skipped using a CMake option:
```bash
$ cmake ../quick_sort -DCOMPILE_UNIT_TESTS=On
$ cmake ../quick_sort -DCOMPILE_UNIT_TESTS=Off
```
or using `cmake-gui`, `ccmake`, etc.
Tests *are* compiled by default.

Tests are then compiled along with production code:
```bash
$ make
```

Run all tests using CTest:
```bash
$ ctest
# or
$ make test         # Does not recompile source!
```

Individual test executables are located in `bin/`. These give verbose output and options.

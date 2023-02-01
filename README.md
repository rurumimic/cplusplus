# C++ 

## Tools

- clang
- cmake: [repo](https://github.com/Kitware/CMake), [tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html), [tutorial code](https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial)
- gnu global

---

## Hello, World!

- [hello world](src/helloworld/main.cpp)

```bash
src/helloworld
├── CMakeLists.txt
├── GPATH
├── GRTAGS
├── GTAGS
├── Makefile
├── build/
├── build.ninja
└── main.cpp
```

### gtags

```bash
gtags
```

spacevim: [gtags](https://spacevim.org/layers/gtags/)

- `Space` + `m` + `g`
  - `Space` + `m` + `g` + `f`: list of objects
  - `Space` + `m` + `g` + `d`: find definitions
  - `Space` + `m` + `g` + `r`: find references
  - `Space` + `m` + `g` + `g`: find cursor string

### Build

```bash
export CC=/opt/local/bin/clang
export CXX=/opt/local/bin/clang++
```

#### clang

```bash
clang++ -o helloworld main.cpp
g++ -o helloworld main.cpp
```

```bash
./helloworld

Hello, World!
```

#### make

```bash
make
```

```bash
./helloworld

Hello, World!
```

#### cmake

```bash
cmake -S . -B build
```

<details>
    <summary>specify a build directory</summary>

```bash
-- The C compiler identification is Clang 14.0.6
-- The CXX compiler identification is Clang 14.0.6
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /opt/local/bin/clang - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /opt/local/bin/clang++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: cplusplus/src/helloworld/build
```
</details>

```bash
cmake --build build
```

<details>
    <summary>Build a CMake-generated project binary tree</summary>

```bash
[ 50%] Building CXX object CMakeFiles/HelloWorld.dir/main.cpp.o
[100%] Linking CXX executable HelloWorld
[100%] Built target HelloWorld
```

</details>

```bash
./build/helloworld

Hello, World!
```

#### ninja

```bash
ninja

[1/1] clang++ -Wall -c main.cpp -o helloworld
```

```bash
./helloworld

Hello, World!
```


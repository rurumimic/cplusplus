# Abseil

- [abseil](https://abseil.io/)
- github: [abseil](https://github.com/abseil/)
  - [abseil/abseil-cpp](https://github.com/abseil/abseil-cpp)

## Build

```bash
git clone https://github.com/abseil/abseil-cpp.git
cd abseil-cpp
```

### CMake

- with clang: `-DCMAKE_CXX_FLAGS="-stdlib=libc++"`
- with ninja: `-GNinja`

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
      -DCMAKE_INSTALL_PREFIX=dist \
      -DCMAKE_CXX_STANDARD=17 \
      -DCMAKE_CXX_FLAGS="-stdlib=libc++" \
      -GNinja \
      -S . -B build
```

Check Install Path:

```bash
grep "CMAKE_INSTALL_PREFIX" build/CMakeCache.txt
```

Build:

```bash
ninja -C build all
# or
cmake --build build --target all
```

Install:

```bash
ninja -C build install
# or
cmake --install build --prefix ./dist
```

#### .clangd

```yaml
CompileFlags:
  CompilationDatabase: "build"
```

#### Usage

```bash
ABSEIL_DIST=$PWD/dist
```

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
      -DCMAKE_INSTALL_PREFIX=dist \
      -DCMAKE_CXX_FLAGS="-stdlib=libc++" \
      -DCMAKE_PREFIX_PATH="$ABSEIL_DIST" \
      -GNinja \
      -S . -B build

```


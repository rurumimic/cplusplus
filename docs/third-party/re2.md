# google/re2

```bash
git clone https://github.com/google/re2.git
cd re2
```

## Build with Clang++

```bash
git clone https://github.com/abseil/abseil-cpp.git
cd abseil-cpp
```

build: [abseil-cpp](./abseil.md)

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
      -DCMAKE_INSTALL_PREFIX=dist \
      -DCMAKE_CXX_FLAGS="-stdlib=libc++" \
      -DCMAKE_PREFIX_PATH="./abseil-cpp/dist" \
      -GNinja \
      -S . -B build
```

```bash
ninja -C build
ninja -C build install
```

#### .clangd

```yaml
CompileFlags:
  CompilationDatabase: "build"
```


# README

## Build and Run

```bash
rm -rf build
```

### CMake

```bash
cmake -S . -B build;
cmake --build build --target clean;
bear -- cmake --build build;
```

### Ninja

```bash
cmake -G Ninja -S . -B build;
ninja -C build clean;
bear -- ninja -C build;
```

### Run

```bash
./build/patterns
./build/abstract_factory/abstract_factory
./build/builder/builder
```

## Format

```bash
clang-format -style=google -dump-config > .clang-format
```


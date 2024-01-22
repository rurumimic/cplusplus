# Pthread RWLock

## Build

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

## Run

```bash
./build/main
```

```bash
Reader 739397
Reader 739397
Writer 739397
```


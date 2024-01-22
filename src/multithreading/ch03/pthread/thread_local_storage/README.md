# Pthread Thread Local Storage

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
Thread 140278503568960 value 2
Thread 140278396614208 value 2
Thread 140278478390848 value 2
Thread 140278495176256 value 2
Thread 140278486783552 value 2
```


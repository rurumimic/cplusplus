# Pthread Mutex

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
Thread: 140378221041216, value: 2
Thread: 140378212648512, value: 3
Thread: 140378229433920, value: 1
Thread: 140378237826624, value: 0
Thread: 140378204255808, value: 4
```


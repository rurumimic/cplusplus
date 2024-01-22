# Pthread Cond

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
Counter value: 1 Thread ID: 0
Counter value: 2 Thread ID: 1
Thread ID: 2 waiting on condition variable
Counter value: 3 Thread ID: 0
Counter value: 4 Thread ID: 1
Counter value: 5 Thread ID: 1
Counter value: 6 Thread ID: 0
Counter value: 7 Thread ID: 1
Counter value: 8 Thread ID: 0
Counter value: 9 Thread ID: 1
Counter value: 10 Thread ID: 0
Counter value: 11 Thread ID: 0
Counter value: 12 Thread ID: 1
Counter hit limit: 12
Thread ID: 2 Condition variable signal received
Counter value: 13 Thread ID: 1
Counter value: 14 Thread ID: 0
Counter value: 15 Thread ID: 0
Counter value: 16 Thread ID: 1
Counter value: 17 Thread ID: 1
Counter value: 18 Thread ID: 0
Counter value: 19 Thread ID: 1
Counter value: 20 Thread ID: 0
```


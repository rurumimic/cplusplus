# Scheduler

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
Initialised.
Request:  3 on thread 3
Request:  1 on thread 2
Request:  7 on thread 7
Finished: 7 on thread 7
Request:  6 on thread 6
Finished: 6 on thread 6
Request:  0 on thread 1
Finished: 0 on thread 1
Request:  12 on thread 1
Finished: 12 on thread 1
Request:  13 on thread 1
Finished: 13 on thread 1
Request:  5 on thread 5
Finished: 5 on thread 5
Request:  4 on thread 4
Finished: 4 on thread 4
Request:  2 on thread 0
Finished: 2 on thread 0
Request:  17 on thread 0
Finished: 17 on thread 0
Request:  11 on thread 6
Finished: 11 on thread 6
Request:  19 on thread 6
Finished: 19 on thread 6
Request:  20 on thread 6
Finished: 20 on thread 6
Request:  21 on thread 6
Finished: 21 on thread 6
Request:  22 on thread 6
Finished: 22 on thread 6
Request:  23 on thread 6
Finished: 23 on thread 6
Request:  24 on thread 6
Finished: 24 on thread 6
Request:  25 on thread 6
Finished: 25 on thread 6
Request:  8 on thread 8
Finished: 8 on thread 8
Request:  27 on thread 8
Finished: 27 on thread 8
Request:  9 on thread 9
Finished: 9 on thread 9
Request:  10 on thread 7
Finished: 10 on thread 7
Request:  14 on thread 1
Finished: 14 on thread 1
Request:  31 on thread 1
Finished: 31 on thread 1
Request:  32 on thread 1
Request:  28 on thread 8
Finished: 28 on thread 8
Request:  33 on thread 8
Finished: 33 on thread 8
Request:  34 on thread 8
Finished: 34 on thread 8
Request:  35 on thread 8
Request:  30 on thread 7
Finished: 30 on thread 7
Request:  36 on thread 7
Finished: 36 on thread 7
Request:  37 on thread 7
Finished: 37 on thread 7
Request:  38 on thread 7
Finished: 38 on thread 7
Request:  39 on thread 7
Finished: 39 on thread 7
Request:  40 on thread 7
Finished: 40 on thread 7
Request:  41 on thread 7
Finished: 41 on thread 7
Request:  42 on thread 7
Finished: 42 on thread 7
Request:  43 on thread 7
Finished: 43 on thread 7
Request:  44 on thread 7
Finished: 44 on thread 7
Request:  45 on thread 7
Finished: 45 on thread 7
Request:  46 on thread 7
Finished: 46 on thread 7
Request:  47 on thread 7
Finished: 47 on thread 7
Request:  48 on thread 7
Finished: 48 on thread 7
Request:  49 on thread 7
Finished: 49 on thread 7
Finished: 3 on thread 3
Finished: 32 on thread 1
Request:  16 on thread 4
Finished: 16 on thread 4
Request:  18 on thread 0
Finished: 18 on thread 0
Finished: 1 on thread 2
Finished: 35 on thread 8
Request:  26 on thread 6
Finished: 26 on thread 6
Request:  29 on thread 9
Finished: 29 on thread 9
Request:  15 on thread 5
Finished: 15 on thread 5
Clean-up.
```

# Multithreading

## Build

```bash
cmake -S . -B build;
cmake --build build --target clean;
bear -- cmake --build build;
```

## Run

```bash
./build/main;
```

```bash
Thread 1 started.
Thread 2 started.
Thread 3 started.
Thread 2 add 6. New vlue: 48
Thread 1 add 0. New vlue: 42
Thread 3 add 2. New vlue: 44
Thread 4 started.
Thread 4 add 4. New vlue: 46
values[0] = 42
values[2] = 48
values[1] = 42
values[3] = 44
values[4] = 46
```


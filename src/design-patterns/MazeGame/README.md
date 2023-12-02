# README

## Build and Run

```bash
cmake -S . -B build
cmake --build build --target clean
bear -- cmake --build build
```

### Run

```bash
./build/Patterns
```

## Format

```bash
clang-format -style=google -dump-config > .clang-format
```


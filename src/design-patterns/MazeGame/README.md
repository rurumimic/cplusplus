# README

## Build and Run

```bash
cmake -S . -B build;
cmake --build build --target clean;
bear -- cmake --build build;
```

### Run

```bash
./build/patterns
./build/abstract_factory/abstract_factory
```

## Format

```bash
clang-format -style=google -dump-config > .clang-format
```


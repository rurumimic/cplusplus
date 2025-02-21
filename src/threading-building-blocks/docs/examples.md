# Examples

- github: [examples](https://github.com/uxlfoundation/oneTBB/tree/master/examples/)

## Getting Started

- github: [getting_started](https://github.com/uxlfoundation/oneTBB/tree/master/examples/getting_started)

### sub_string_finder

- github: [sub_string_finder](https://github.com/uxlfoundation/oneTBB/tree/master/examples/getting_started/sub_string_finder)

```bash
cd oneTBB/examples/getting_started/sub_string_finder
```

#### Build sub_string_finder

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON --debug-output -S . -B build
make -C build sub_string_finder VERBOSE=1
```

- `CMAKE_EXPORT_COMPILE_COMMANDS=ON`: generate `compile_commands.json` file
- `--debug-output`: print debug information
- `VERBOSE=1`: print verbose information

```bash
cmake --debug-output -S . -B build
bear -- make -C build sub_string_finder VERBOSE=1
```

- `bear`: generate `compile_commands.json` file. if `CMAKE_EXPORT_COMPILE_COMMANDS=ON` is not set

#### Run sub_string_finder

```bash
./build/sub_string_finder_simple
./build/sub_string_finder_extended
./build/sub_string_finder_pretty
```


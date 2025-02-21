# Init

## Build

```bash
cmake \
-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
-DENABLE_FORMAT=ON \
--debug-output \
-S . -B build
```

- `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON` export compile commands
- `-DENABLE_FORMAT=ON` enable format target
- `-DFORMAT_STYLE=Google` use Google format style
- `--debug-output` print debug output
- `-S .` source directory
- `-B build` build directory

```bash
make -C build
```

## Run

```bash
./build/init
```

## Format

### Make .clang-format

```bash
make -C build clang-format
```

### Format code

```bash
make -C build format
```



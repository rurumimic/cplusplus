# C++ 23

- README: [Importing the C++23 Standard Library as a module](https://github.com/bshoshany/thread-pool#importing-the-c23-standard-library-as-a-module)

My clang version:

```bash
Ubuntu clang version 19.1.7 (++20250114103320+cd708029e0b2-1~exp1~20250114103432.75)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/lib/llvm-19/bin
```

## Enabling `import std`

### Compiling with Clang and LLVM libc++ using `import std`

```bash
mkdir -p build
```

#### std.cppm

Before compiling the std module, find `std.cppm`:

```bash
ls -al /usr/lib/llvm-19/share/libc++/v1/std.cppm
```

set `STD_CPPM` to the path of `std.cppm`:

```bash
STD_CPPM=/usr/lib/llvm-19/share/libc++/v1/std.cppm
```

#### build std.pcm

```bash
clang++ $STD_CPPM --precompile -std=c++23 -o build/std.pcm -Wno-reserved-module-identifier -stdlib=libc++
```

#### build BS.thread_pool.pcm

```bash
clang++ modules/BS.thread_pool.cppm --precompile -fmodule-file="std=build/std.pcm" -std=c++23 -I include -o build/BS.thread_pool.pcm -D BS_THREAD_POOL_IMPORT_STD -D BS_THREAD_POOL_NATIVE_EXTENSIONS -stdlib=libc++
```

#### build BS_thread_pool_test

```bash
clang++ tests/BS_thread_pool_test.cpp -fmodule-file="std=build/std.pcm" -fmodule-file="BS.thread_pool=build/BS.thread_pool.pcm" -std=c++23 -o build/BS_thread_pool_test -D BS_THREAD_POOL_TEST_IMPORT_MODULE -D BS_THREAD_POOL_IMPORT_STD -D BS_THREAD_POOL_NATIVE_EXTENSIONS -stdlib=libc++
```

#### run BS_thread_pool_test

```bash
./build/BS_thread_pool_test
```


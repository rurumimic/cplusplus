# C++ 20

- README: [Importing the library as a C++20 module](https://github.com/bshoshany/thread-pool#importing-the-library-as-a-c20-module)

My clang version:

```bash
Ubuntu clang version 19.1.7 (++20250114103320+cd708029e0b2-1~exp1~20250114103432.75)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/lib/llvm-19/bin
```

## Compiling the module

### Compiling with Clang using `import BS.thread_pool`

```bash
mkdir -p build
```

#### build BS.thread_pool.pcm

```bash
clang++ modules/BS.thread_pool.cppm --precompile -std=c++20 -I include -o build/BS.thread_pool.pcm -D BS_THREAD_POOL_NATIVE_EXTENSIONS -stdlib=libc++
```

#### build BS_thread_pool_test

```bash
clang++ tests/BS_thread_pool_test.cpp -fmodule-file="BS.thread_pool=build/BS.thread_pool.pcm" -std=c++20 -o build/BS_thread_pool_test -D BS_THREAD_POOL_TEST_IMPORT_MODULE -D BS_THREAD_POOL_NATIVE_EXTENSIONS -stdlib=libc++
```

- `-D BS_THREAD_POOL_TEST_IMPORT_MODULE`: **this macro is only used by the test program**

#### run BS_thread_pool_test

```bash
./build/BS_thread_pool_test
```


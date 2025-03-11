#!/bin/sh

cmake \
-DCMAKE_CXX_FLAGS="-DBS_THREAD_POOL_NATIVE_EXTENSIONS" \
-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
-DENABLE_FORMAT=ON \
-S . -B build \
-G Ninja

ninja -C build

./build/main


#!/bin/sh

# https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html
build_type=RELEASE

rm -r build
mkdir build
cd build

conan install ..
cmake .. -DCMAKE_BUILD_TYPE=$build_type
cmake --build .

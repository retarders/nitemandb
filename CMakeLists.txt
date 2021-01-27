cmake_minimum_required(VERSION 3.18)
project(NitemanDB)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(niteman src/niteman.cc)
target_link_libraries(niteman ${CONAN_LIBS})

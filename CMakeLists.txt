cmake_minimum_required(VERSION 3.12)
project(bit_tricks)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)
FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.7.1  # Replace with the desired version/tag
)
FetchContent_MakeAvailable(googlebenchmark)

add_executable(bt_benchmarks
    src/benchmarks.cpp)
target_include_directories(bt_benchmarks
    PUBLIC include
)
set_property(TARGET bt_benchmarks PROPERTY CXX_STANDARD 20)

target_link_libraries(bt_benchmarks
    benchmark
    benchmark_main)

add_executable(bt_unittests
    src/unittests.cpp)
target_include_directories(bt_unittests
    PUBLIC include
    PUBLIC ${GOOGLETEST_SOURCE_DIR}/include
)
set_property(TARGET bt_unittests PROPERTY CXX_STANDARD 20)
target_link_libraries(bt_unittests
    gtest
    gtest_main)

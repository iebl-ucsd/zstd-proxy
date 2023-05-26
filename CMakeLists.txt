cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0077 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
cmake_minimum_required(VERSION 3.13)

project(zstd-proxy VERSION 0.0.1)


find_package(zstd REQUIRED)
add_executable(
        zstd_proxy
        src/zstd-proxy.c
        src/zstd-proxy.h
        src/zstd-proxy-posix.c
        src/zstd_main.cpp)
target_link_libraries(zstd_proxy zstd::libzstd_shared)
target_compile_features(zstd_proxy PRIVATE cxx_std_17)

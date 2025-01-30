cmake_minimum_required(VERSION 3.5)

project(KVData)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
set(CMAKE_CXX_STANDARD 17)

add_library(libKVData)

target_compile_options(libKVData PRIVATE -Wall -Wunused-variable)

target_include_directories(libKVData PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if(KV_DEBUG)
message("debug")
    add_compile_options("-DKV_DEBUG")
endif()

add_subdirectory(src)
add_subdirectory(test)

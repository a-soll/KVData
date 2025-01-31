set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(test
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(test_keyval
    ${CMAKE_CURRENT_SOURCE_DIR}/test_keyval.cpp
)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(test_keyval libKVData)
target_link_libraries(test libKVData)

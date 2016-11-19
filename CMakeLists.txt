cmake_minimum_required(VERSION 2.8)
set(SOURCE_CODE_FILES pack comprehension quicksort reverse)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
add_definitions("-std=c++11")

foreach(SOURCE_CODE_NAME ${SOURCE_CODE_FILES})
    add_executable(${SOURCE_CODE_NAME} ${SOURCE_CODE_NAME}.cpp)
endforeach(SOURCE_CODE_NAME)

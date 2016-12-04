include_directories(${PROJECT_SOURCE_DIR})
add_definitions("-std=c++11")

set(SOURCE_CODE_FILES pack reverse max foldl filter quicksort)
foreach(SOURCE_CODE_NAME ${SOURCE_CODE_FILES})
    add_executable(${SOURCE_CODE_NAME} ${SOURCE_CODE_NAME}.cpp)
endforeach(SOURCE_CODE_NAME)

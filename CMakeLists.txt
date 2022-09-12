cmake_minimum_required(VERSION 3.23)
project(LeetCodeSandbox)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SRCS *.cpp)
foreach (file ${SRCS})
    get_filename_component(file ${file} NAME)
    string(REPLACE ".cpp" "" name ${file})
    add_executable(${name} ${file})
endforeach ()

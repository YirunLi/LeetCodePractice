PROJECT(search)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
include_directories("D:/LeetCode/DataStructure/Tree")
include_directories("D:/LeetCode/DataStructure/ListNode")

add_executable(${PROJECT_NAME} src/main.cpp)
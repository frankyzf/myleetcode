cmake_minimum_required(VERSION 3.3)
project(myleetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(myleetcode ${SOURCE_FILES})
add_executable(totalNQueens totalNQueens.cpp)
add_executable(longestconsective longestconsective.cpp)
add_executable(findMedianSortedArray findMedianSortedArray.cpp)
add_executable(maxSlidingWindow maxSlidingWindow.cpp)
add_executable(getSkyline getSkyline.cpp)
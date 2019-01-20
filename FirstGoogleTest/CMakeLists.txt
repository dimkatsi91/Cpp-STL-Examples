cmake_minimum_required(VERSION 2.6)

project(FirstGoogleTest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main testHeader.cpp)
target_link_libraries(main ${GTEST_LIBRARIES} pthread)


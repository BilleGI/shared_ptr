cmake_minimum_required(VERSION 3.5)

add_executable(clever_ptr main.cpp ${MY_INCLUDE_DIR}/shared_ptr.h #[[shared_ptr.cpp]]  ${MY_INCLUDE_DIR}/toy.h toy.cpp   ${MY_INCLUDE_DIR}/dog.h dog.cpp)

target_include_directories(clever_ptr PUBLIC ${MY_INCLUDE_DIR})

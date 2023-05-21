cmake_minimum_required(VERSION 3.5)

project("Shared ptr toy" VERSION 1.0)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(clever_ptr main.cpp shared_ptr.h #[[shared_ptr.cpp]] toy.h toy.cpp  dog.h dog.cpp)
    add_subdirectory(src)

install(TARGETS clever_ptr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

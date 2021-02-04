cmake_minimum_required(VERSION 3.17)
project(exampleGTK_1)

set(CMAKE_CXX_STANDARD 14)
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
add_executable(exampleGTK_1 main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lcurl")
set(SOURCE_FILES main.cpp)
target_link_libraries(${PROJECT_NAME} curl)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(exampleGTK_1 ${GTK3_LIBRARIES})
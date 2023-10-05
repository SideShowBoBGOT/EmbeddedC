cmake_minimum_required(VERSION 3.26)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} main.c list.h list.c book.h)

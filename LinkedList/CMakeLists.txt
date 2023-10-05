cmake_minimum_required(VERSION 3.26)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} main.c containers/include/list.h containers/src/list.c book.h
        book.c
        containers/src/node.h
        containers/src/node.c)

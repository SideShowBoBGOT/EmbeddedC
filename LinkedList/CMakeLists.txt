cmake_minimum_required(VERSION 3.26)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedList main.c
        SLinkedList.h
        SLinkedList.cpp
        SBook.h)

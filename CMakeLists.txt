cmake_minimum_required(VERSION 3.17)
project(study C)

set(CMAKE_C_STANDARD 99)

add_executable(study main.c ADT/LinkedList.c ADT/LinkedList.h ADT/List.h)
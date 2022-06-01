cmake_minimum_required(VERSION 3.16)
project(Omnia)

set(CMAKE_CXX_STANDARD 20)

add_executable(Omnia main.cpp omnia_tokenizer.h omnia_tokenizer.cpp)
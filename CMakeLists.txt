cmake_minimum_required(VERSION 3.21)
project(line_editor)

set(CMAKE_CXX_STANDARD 14)

add_executable(line_editor src/main.cpp src/Node.h src/List.cpp src/List.h src/FileIO.cpp src/FileIO.h src/Parser.cpp src/Parser.h)

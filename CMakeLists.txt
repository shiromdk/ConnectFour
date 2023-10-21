cmake_minimum_required(VERSION 3.26)
project(Connect4)

set(CMAKE_CXX_STANDARD 23)

add_executable(Connect4 main.cpp
        src/Bitboard.cpp
        src/Bitboard.h
        src/ConnectFour.cpp
        src/ConnectFour.h
        src/typedefs.h
)

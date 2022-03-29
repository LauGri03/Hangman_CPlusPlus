cmake_minimum_required( VERSION 3.0 )

project( Hangman )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories( ./include ./src)

add_executable( Hangman ./src/main.cpp ./src/hangman.cpp ./src/hangman.h)


cmake_minimum_required(VERSION 3.25)
project(gameOfLife)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
add_executable(gameOfLife.elf src/copyBoard.c  src/countNeighbours.c  src/gameOfLife.c  src/randomInitBoard.c  src/printBoard.c  src/spreadLife.c)

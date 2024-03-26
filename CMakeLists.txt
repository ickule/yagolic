cmake_minimum_required(VERSION 3.25)
project(yagolic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(
    yagolic
    src/copy_board.c
    src/yagolic.c
    src/init_board.c
    src/print_board.c
    src/spread_life.c
    src/null_pointer_check.c
    src/clear_screen.c
    )
target_include_directories(yagolic PRIVATE include)

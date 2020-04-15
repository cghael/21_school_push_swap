cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 90)

set(SOURCES src/main.c
        src/ft_check_args.c)

include_directories(includes)
include_directories(ft_printf/includes)
include_directories(ft_printf/libft/inc)

add_executable(push_swap ${SOURCES})

add_subdirectory(ft_printf)

target_link_libraries(push_swap libftprintf)


cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 90)

set(SOURCES src/main.c
        src/ft_check_n_write_args.c
        src/ft_one_agr.c
        src/ft_multi_arg.c
        src/ft_new_elem_add.c
        src/ft_free_stack.c src/ft_sort_stack_a.c src/ft_check_stack_sorted.c)

include_directories(includes)
include_directories(ft_printf/includes)
include_directories(ft_printf/libft/inc)

add_subdirectory(ft_printf)

add_executable(push_swap ${SOURCES})

target_link_libraries(push_swap libftprintf)


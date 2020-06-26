cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 90)

set(SOURCES src/main.c
        src/ft_check_n_write_args.c
        src/ft_one_agr.c
        src/ft_multi_arg.c
        src/ft_new_elem_add.c
        src/ft_free_stack.c
        src/ft_sort_stacks.c
        src/ft_check_stack_sorted.c
        src/ft_print_operations.c
        src/ft_new_order_add.c
        src/ft_free_cmd_stack.c
        src/ft_free_push_swap_mem.c
        src/ft_pa_pb.c
        src/ft_print_stack_step.c
        src/ft_ra_rb.c
        src/ft_push_to_dst_before_pivot.c
        src/ft_adjust_big_to_small_stack.c
        src/ft_rra_rrb.c
        src/ft_find_rotate_side.c
        src/ft_nearest_smaller_pivot.c
        src/ft_sa_sb.c
        src/ft_create_t_st_elem.c src/ft_sort_two_three_elem.c src/ft_sort_last_step.c src/ft_find_pivot.c src/ft_side_to_rotate.c src/ft_start_sorting.c src/ft_get_stack_back.c src/ft_need_steps_to_push.c)

include_directories(includes)
include_directories(ft_printf/includes)
include_directories(ft_printf/libft/inc)

add_subdirectory(ft_printf)

add_executable(push_swap ${SOURCES})

target_link_libraries(push_swap libftprintf)


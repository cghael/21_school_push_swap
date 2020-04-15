cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 90)


#set(SOURCES src/main.c
#        src/ft_check_args.c)
#set(HEADERS includes/push_swap.h)

#add_executable(push_swap ${SOURCES} ${HEADERS})
add_executable(push_swap main.c ft_check_args.c push_swap.h)

add_subdirectory(libft)
#target_include_directories(push_swap libft/includes/)
target_link_libraries(push_swap libft)


#target_include_directories(push_swap PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

#target_include_directories(push_swap PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libft/includes)

#find_library(FT libft.a)
#target_link_libraries(FT LINK_PUBLIC ${LIBFT})


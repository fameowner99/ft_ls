cmake_minimum_required(VERSION 3.9)
project(ft_ls C)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/libft)
include_directories(${CMAKE_SOURCE_DIR}/includes)

add_executable(ft_ls
        srcs/flag_tools.c
        srcs/ft_ls.c
        srcs/main.c
        srcs/main_part.c
        srcs/manage_list_container.c
        srcs/parsing.c
        srcs/print_container.c
        srcs/sort_list.c
        srcs/manage_data_container.c
        srcs/print_directory.c
        srcs/recursion.c
        srcs/print_flag_l.c)

add_library(libft STATIC IMPORTED) # Создание статической библиотеки
set_property(TARGET libft PROPERTY
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)

target_link_libraries(ft_ls libft)

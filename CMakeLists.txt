cmake_minimum_required(VERSION 3.25)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(push_swap
        ft_push.c
        ft_reverse_rotate.c
        ft_rotate.c
        ft_swap.c
        push_swap.c
        push_swap.h)

cmake_minimum_required(VERSION 3.29)
project(TextEditor C)

set(CMAKE_C_STANDARD 11)

add_executable(TextEditor main.c
        commands.c
        commands.h
        file_interaction.c
        file_interaction.h)

cmake_minimum_required(VERSION 3.23)
project(C_Project C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Project main.c Admin_Program.h Admin_Program.c Client_Program.c Client_Program.h Menus_Interface.c Menus_Interface.h)

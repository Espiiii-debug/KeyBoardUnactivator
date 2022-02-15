cmake_minimum_required(VERSION 3.20)
project(KeyBoardHook)

set(CMAKE_CXX_STANDARD 14)

add_executable(KeyBoardHook main.cpp hookManager/Hook.cpp keyStateManager/KeyState.cpp keyStateManager/KeyState.h)

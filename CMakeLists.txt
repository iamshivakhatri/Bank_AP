cmake_minimum_required(VERSION 3.27)
project(khatri_shiva_prog1csc402)

set(CMAKE_CXX_STANDARD 17)

add_executable(khatri_shiva_prog1csc402 main.cpp
        Account.cpp Account.h
        ATM.h
        Bank.h
        Bank.cpp
        ATM.cpp)


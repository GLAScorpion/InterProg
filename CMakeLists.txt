cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD)
project(InterProg)
add_executable(booktester
booktester.cpp
Book.cpp
ISBN.cpp
Date.cpp
)
add_executable(datetester
    Datetester.cpp
    Date.cpp
)
add_executable(isbntester
    ISBNtester.cpp
    ISBN.cpp
)
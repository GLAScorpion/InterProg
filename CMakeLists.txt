cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD)
project(InterProg)
add_executable(book_tester.bin
book_tester.cpp
book.cpp
isbn.cpp
date.cpp
)
add_executable(date_tester.bin
date_tester.cpp
date.cpp
)
add_executable(isbn_tester.bin
isbn_tester.cpp
isbn.cpp
)
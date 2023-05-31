cmake_minimum_required(VERSION 3.25)
project(Hw2Library)

set(CMAKE_CXX_STANDARD 11)

add_executable(Hw2Library main.cpp
        library/src/print_editions/PrintEdition.cpp library/include/print_editions/PrintEdition.h
        library/src/print_editions/Book.cpp library/include/print_editions/Book.h
        library/src/print_editions/Periodical.cpp library/include/print_editions/Periodical.h
        library/src/print_editions/Comic.cpp library/include/print_editions/Comic.h
        library/src/user/User.cpp library/include/user/User.h
        library/src/Library.cpp library/include/Library.h
        library/include/utility.h)

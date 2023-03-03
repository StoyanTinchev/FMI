cmake_minimum_required(VERSION 3.23)
project(Dr1_fn3MI0700193)

set(CMAKE_CXX_STANDARD 20)

set(-DCMAKE_CXX_FLAGS="-fuse-lobjc.A")

add_executable(ZAD1 zad1.cpp)
add_executable(ZAD2 zad2.cpp)
add_executable(ZAD3 zad3.cpp)
add_executable(ZAD4 zad4.cpp)
add_executable(ZAD5 zad5.cpp)
add_executable(ZAD6 zad6.cpp)

SET(CMAKE_CXX_FLAGS "-I/usr/X11/include -L/usr/X11/lib -lX11")

#set(CMAKE_EXE_LINKER_FLAGS -I/usr/X11/include /usr/X11/lib -lX11)
set(MID_FINGER_SRC mid_finger.cpp)
add_executable(MID_FINGER "${MID_FINGER_SRC}")
set_target_properties(MID_FINGER PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(MID_FINGER PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(MID_FINGER "${MID_FINGER}")

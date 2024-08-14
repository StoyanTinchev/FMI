# Target for the expression processing library
add_library(simulator-lib STATIC
        student.cpp
        student.h
        group.cpp
        group.h
        bar.cpp
        bar.h)

target_sources(
        simulator-lib
        PRIVATE
        "bar-simulator.cpp"
        "bar-simulator.h"
)

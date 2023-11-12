cmake_minimum_required(VERSION 3.25)
project(OOPTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOPTest main.cpp
        include/Sound.h
        include/Silence.h
        include/SoundFromFile.h
        include/PeriodicSound.h
        include/Mix.h
        include/Sequence.h
        include/Effect.h
        Playlist/Playlist.h)

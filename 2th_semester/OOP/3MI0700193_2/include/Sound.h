#ifndef OOPTEST_SOUND_H
#define OOPTEST_SOUND_H

#include <iostream>
#include <fstream>
#include <new>
#include <cstring>
#include <ctime>
#include <cmath>
#include <exception>
#include <stdexcept>

template<typename T, T M>
class Sound {
public:
    virtual ~Sound() = default;

    virtual T operator[](size_t i) const = 0;

    virtual size_t length() const = 0;
};

template<typename T, T M>
void Save(const Sound<T, M> &sound, const char* filename) {
    std::ofstream output(filename, std::ios::binary);
    for (size_t i = 0; i < sound.length(); ++i) {
        T value = sound[i];
        output.write(reinterpret_cast<const char *>(&value), sizeof(T));
    }
}


#endif //OOPTEST_SOUND_H

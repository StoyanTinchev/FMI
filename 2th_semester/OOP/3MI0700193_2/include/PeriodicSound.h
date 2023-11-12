#ifndef OOPTEST_PERIODICSOUND_H
#define OOPTEST_PERIODICSOUND_H

#include "Sound.h"

template<typename T, T M>
class PeriodicSound : public Sound<T, M> {
public:
    PeriodicSound(const T *pattern, size_t pattern_length, size_t repeat) : _pattern(
            new(std::nothrow) T[pattern_length]), _pattern_length(pattern_length), _repeat(repeat) {
        if (!_pattern) {
            throw std::runtime_error("Cannot allocate memory!");
        }
        std::copy(pattern, pattern + pattern_length, _pattern);
    };

    ~PeriodicSound() override {
        delete[] _pattern;
    };

    T operator[](size_t i) const override {
        return _pattern[i % _pattern_length];
    };

    size_t length() const override {
        return _pattern_length * _repeat;
    };

private:
    T *_pattern;
    size_t _pattern_length;
    size_t _repeat;
};

#endif //OOPTEST_PERIODICSOUND_H

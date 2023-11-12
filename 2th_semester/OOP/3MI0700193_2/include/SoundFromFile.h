#ifndef OOPTEST_SOUNDFROMFILE_H
#define OOPTEST_SOUNDFROMFILE_H

#include "Sound.h"

template<typename T, T M>
class SoundFromFile : public Sound<T, M> {
public:
    SoundFromFile(const char *filename) : _owns_samples(true) {
        std::ifstream input(filename, std::ios::binary);
        if (!input.is_open()) {
            throw std::runtime_error("Cannot open the file!");
        }

        input.seekg(0, std::ios::end);
        _length = input.tellg() / sizeof(T);
        input.seekg(0, std::ios::beg);

        _samples = new(std::nothrow) T[_length];
        if (!_samples) {
            throw std::runtime_error("Cannot allocate memory!");
        }

        input.read(reinterpret_cast<char *>(_samples), _length * sizeof(T));

        if (!input) {
            delete[] _samples;
            throw std::runtime_error("Cannot read the file!");
        }
    };

    SoundFromFile(T *samples, size_t length) : _samples(samples),
                                               _length(length),
                                               _owns_samples(false) {}

    ~SoundFromFile() override {
        if (_owns_samples)
            delete[] _samples;
    };

    T operator[](size_t i) const override {
        return _samples[i];
    };

    size_t length() const override {
        return _length;
    };

private:
    T *_samples;
    size_t _length;
    bool _owns_samples;
};

#endif //OOPTEST_SOUNDFROMFILE_H

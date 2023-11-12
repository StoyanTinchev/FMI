#ifndef OOPTEST_SILENCE_H
#define OOPTEST_SILENCE_H

#include "Sound.h"

template<typename T, T M>
class Silence : public Sound<T, M> {
public:
    Silence(size_t length) : _length(length) {}

    T operator[](size_t i) const override { return 0; }

    size_t length() const override { return _length; }

private:
    size_t _length;
};

#endif //OOPTEST_SILENCE_H

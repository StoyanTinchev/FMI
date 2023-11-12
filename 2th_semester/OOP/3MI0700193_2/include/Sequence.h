#ifndef OOPTEST_SEQUENCE_H
#define OOPTEST_SEQUENCE_H

#include "Sound.h"

template<typename T, T M>
class Sequence : public Sound<T, M> {
public:
    Sequence(Sound<T, M> *const *sounds,
             size_t sound_count,
             bool owns_sounds = false) : _sounds(new(std::nothrow) Sound<T, M> *[sound_count]),
                                         _sound_count(sound_count),
                                         _lengths(new(std::nothrow) size_t[sound_count]),
                                         _owns_sounds(owns_sounds) {
        if (!_sounds || !_lengths) {
            throw std::runtime_error("Cannot allocate memory!");
        }
        std::copy(sounds, sounds + sound_count, _sounds);

        _length = 0;
        for (size_t i = 0; i < sound_count; ++i) {
            _lengths[i] = sounds[i]->length();
            _length += _lengths[i];
        }
    }

    ~Sequence() override {
        if (_owns_sounds) {
            delete[] _sounds;
            delete[] _lengths;
        }
    };

    T operator[](size_t i) const override {
        for (size_t j = 0; j < _sound_count; ++j) {
            if (i < _lengths[j]) {
                return (*_sounds[j])[i];
            } else {
                i -= _lengths[j];
            }
        }
        throw std::out_of_range("Index out of range!");
    };

    size_t length() const override {
        return _length;
    };

private:
    Sound<T, M> **_sounds;
    size_t _sound_count;
    size_t _length;
    size_t *_lengths;
    bool _owns_sounds;
};

#endif //OOPTEST_SEQUENCE_H

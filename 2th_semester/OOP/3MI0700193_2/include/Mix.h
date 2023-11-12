#ifndef OOPTEST_MIX_H
#define OOPTEST_MIX_H

#include "Sound.h"

template<typename T, T M>
class Mix : public Sound<T, M> {
public:
    Mix(Sound<T, M> *const *sounds,
        size_t sound_count,
        bool owns_sounds = false) : _sounds(new(std::nothrow) Sound<T, M> *[sound_count]),
                                    _sound_count(sound_count),
                                    _owns_sounds(owns_sounds) {
        if (!_sounds) {
            throw std::runtime_error("Cannot allocate memory!");
        }
        std::copy(sounds, sounds + sound_count, _sounds);

        _length = 0;
        for (size_t i = 0; i < sound_count; ++i) {
            if (sounds[i]->length() > _length) {
                _length = sounds[i]->length();
            }
        }
    };

    ~Mix() override {
        if (_owns_sounds)
            delete[] _sounds;
    };

    T operator[](size_t i) const override {
        T sum = 0;
        for (size_t j = 0; j < _sound_count; ++j) {
            if (i < _sounds[j]->length()) {
                sum += (*_sounds[j])[i];
            }
        }
        T value = sum / static_cast<T>(_sound_count);

        if (value < -M) {
            return -M;
        }
        if (value > M) {
            return M;
        }
        return value;
    };

    size_t length() const override {
        return _length;
    };

private:
    Sound<T, M> **_sounds;
    size_t _sound_count;
    size_t _length;
    bool _owns_sounds;
};

#endif //OOPTEST_MIX_H

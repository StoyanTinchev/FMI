#ifndef OOPTEST_EFFECT_H
#define OOPTEST_EFFECT_H

#include <functional>
#include "Sound.h"

template<typename T, T M>
class Effect : public Sound<T, M> {
public:
    using TransformFunc = std::function<T(const T &, size_t)>;

    Effect(Sound<T, M> *sound, TransformFunc transformation) : _sound(sound),
                                                               _transformation(transformation) {
    };

    T operator[](size_t i) const override {
        T sample = (*_sound)[i];
        T transformed_sample = _transformation(sample, i);

        if (transformed_sample > M) {
            return M;
        } else if (transformed_sample < -M) {
            return -M;
        }
        return transformed_sample;
    };

    size_t length() const override {
        return _sound->length();
    };

private:
    Sound<T, M> *_sound;
    TransformFunc _transformation;
};

#endif //OOPTEST_EFFECT_H

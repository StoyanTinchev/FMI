#ifndef OOPTEST_PLAYLIST_H
#define OOPTEST_PLAYLIST_H

#include "../include/Effect.h"
#include "../include/Silence.h"
#include "../include/SoundFromFile.h"

template<typename T, T M>
class Playlist {
public:
    Playlist(const char *filename) : _sounds(nullptr), _size(0), _capacity(0) {
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            throw std::runtime_error("Failed to open the file " + std::string(filename));
        }

        char line[1000];
        while (infile) {
            if (!infile.getline(line, sizeof(line))) {
                if (infile.eof()) {
                    break;
                } else {
                    throw std::runtime_error("Failed to read from the file " + std::string(filename));
                }
            }
            parseLine(line);
        }
    };

    ~Playlist() {
        for (size_t i = 0; i < _size; i++) {
            delete _sounds[i];
        }
        delete[] _sounds;
    };

    const Sound<T, M> &operator[](size_t i) const {
        if (i >= _size) {
            throw std::out_of_range("Invalid index");
        }
        return *_sounds[i];
    };

    operator Sound<T, M>() {
        size_t totalSize = 0;
        for (size_t i = 0; i < _size; i++) {
            totalSize += _sounds[i]->getLength();
        }

        T *data = new T[totalSize];
        size_t currentIndex = 0;

        for (size_t i = 0; i < _size; i++) {
            T *currentSoundData = _sounds[i]->getData();
            size_t currentSoundLength = _sounds[i]->getLength();

            for (size_t j = 0; j < currentSoundLength; j++) {
                data[currentIndex++] = currentSoundData[j];
            }
        }

        return Sound<T, M>(data, totalSize);
    };

    void saveToBinaryFile(const char *filename) const {
        std::ofstream outfile(filename, std::ios::binary);
        for (size_t i = 0; i < _size; i++) {
            outfile.write(reinterpret_cast<const char *>(&_sounds[i]), sizeof(_sounds[i]));
        }
    };

    size_t size() const {
        return _size;
    }

private:
    void parseLine(char *line) {
        char *type = std::strtok(line, " ");

        Sound<T, M> *newSound = nullptr;

        if (strcmp(type, "Sound") == 0) {
            char *songfile = std::strtok(nullptr, " ");
            T amp = atof(std::strtok(nullptr, " "));
            newSound = new Effect<T, M>(new SoundFromFile<T, M>(songfile),
                                        [=](const T &sample, size_t) { return sample * amp; });

        } else if (strcmp(type, "Pause") == 0) {
            size_t duration = atoi(std::strtok(nullptr, " "));
            newSound = new Silence<T, M>(duration);

        } else if (strcmp(type, "FadeInSong") == 0) {
            char *songfile = std::strtok(nullptr, " ");
            size_t fadeDuration = atoi(std::strtok(nullptr, " "));
            T finalLevel = atof(std::strtok(nullptr, " "));
            newSound = new Effect<T, M>(new SoundFromFile<T, M>(songfile), [=](const T &sample, size_t i) {
                return sample * (i < fadeDuration ? finalLevel * i / fadeDuration : finalLevel);
            });

        } else {
            throw std::runtime_error("Invalid sound type in playlist");
        }

        if (_size >= _capacity) {
            size_t newCapacity = _capacity == 0 ? 1 : _capacity * 2;
            Sound<T, M> **newSounds = new Sound<T, M> *[newCapacity];
            for (size_t i = 0; i < _size; i++) {
                newSounds[i] = _sounds[i];
            }
            delete[] _sounds;
            _sounds = newSounds;
            _capacity = newCapacity;
        }

        _sounds[_size++] = newSound;
    };

    Sound<T, M> **_sounds;
    size_t _size;
    size_t _capacity;
};

#endif //OOPTEST_PLAYLIST_H

#include "Playlist/Playlist.h"

void createBinaryFileFromSound() {
    const size_t size = 100;
    float samples[size];
    for (size_t i = 0; i < size; ++i) {
        samples[i] = (float) i;
    }
    SoundFromFile<float, 1> sound(samples, size);
    Save(sound, "test_sound.bin");
}

int main() {
    createBinaryFileFromSound();

    Playlist<float, 1.0f> myPlaylist("../playlist.txt");

    for(size_t i = 0; i < myPlaylist.size(); ++i) {
        std::cout << "Sound " << i << " length: " << myPlaylist[i].length() << std::endl;
    }

    myPlaylist.saveToBinaryFile("playlist.bin");

    return 0;
}

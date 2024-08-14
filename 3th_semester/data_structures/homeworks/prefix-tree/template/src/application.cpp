#include "FileProcessor.h"
#include "Dictionary.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

/// Display how to use the program from the command line
void displayUsage(const char *executablePath) {
    try {
        fs::path ep(executablePath);

        std::cout
                << "Usage:\n\t"
                << ep.filename()
                << " <dictionary> <filter> <text>"
                << std::endl;
    }
    catch (...) {
        std::cout << "Cannot parse path from argv[0]";
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        displayUsage(argv[0]);
        return 1;
    }

    Dictionary dict;
    FileProcessor processor;
    size_t dictCorrect = 0, dictIncorrect = 0;
    size_t filterCorrect = 0, filterIncorrect = 0;

    std::cout << "Loading dictionary from " << argv[1] << "..." << std::endl;
    processor.processFile(argv[1], dict, false, dictCorrect, dictIncorrect);

    std::cout << std::endl << "Removing the words listed at " << argv[2] << "..." << std::endl;
    processor.processFile(argv[2], dict, true, filterCorrect, filterIncorrect);

    size_t textCorrect = 0, textIncorrect = 0;
    std::cout << std::endl << "Verifying the contents of " << argv[3] << "..." << std::endl;
    processor.checkText(argv[3], dict, textCorrect, textIncorrect);

    std::cout << "\nStatistics:\n"
              << "    Dictionary entries: " << dictCorrect << " correct, " << dictIncorrect << " incorrect\n"
              << "        Filter entries: " << filterCorrect << " correct, " << filterIncorrect << " incorrect\n"
              << "  Resultant dictionary: " << dict.size() << "\n"
              << "         Words in text: " << textCorrect << " correct, " << textIncorrect << " incorrect\n";

    return 0;
}

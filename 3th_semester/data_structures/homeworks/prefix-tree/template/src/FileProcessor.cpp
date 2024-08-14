#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <sstream>

void FileProcessor::processFile(const std::string &path, Dictionary &dict, bool isFilter) {
    size_t correctCount = 0;
    size_t incorrectCount = 0;
    processFile(path, dict, isFilter, correctCount, incorrectCount);
}

void FileProcessor::processFile(const std::string &path, Dictionary &dict, bool isFilter, size_t &correctCount,
                                size_t &incorrectCount) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << path << std::endl;
        return;
    }

    std::string line;
    size_t lineNum = 0;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        lineNum++;

        if (!Dictionary::isCorrectWord(line.c_str())) {
            std::cerr << "ERROR: incorrect entry \"" << line << "\" on line " << lineNum << std::endl;
            incorrectCount++;
            continue;
        }

        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            try {
                if (isFilter) {
                    dict.erase(word.c_str());
                } else {
                    dict.insert(word.c_str());
                }
                correctCount++;
            } catch (const incorrect_word_exception &) {
                std::cerr << "ERROR: incorrect entry \"" << word << "\" on line " << lineNum << std::endl;
                incorrectCount++;
            }
        }
    }
}

void FileProcessor::checkText(const std::string &path, Dictionary &dict, size_t &correctCount, size_t &incorrectCount) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << path << std::endl;
        return;
    }

    std::string line;
    size_t lineNum = 0;
    while (std::getline(file, line)) {
        lineNum++;
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (!dict.contains(word.c_str())) {
                std::cerr << "SPELLING ERROR: \"" << word << "\" on line " << lineNum << std::endl;
                incorrectCount++;
            } else {
                correctCount++;
            }
        }
    }
}

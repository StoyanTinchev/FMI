#pragma once

#include "Dictionary.h"
#include <string>

class FileProcessor {
public:
    void processFile(const std::string &path, Dictionary &dict, bool isFilter = false);

    void
    processFile(const std::string &path, Dictionary &dict, bool isFilter, size_t &correctCount, size_t &incorrectCount);

    void checkText(const std::string &path, Dictionary &dict, size_t &correctCount, size_t &incorrectCount);

};

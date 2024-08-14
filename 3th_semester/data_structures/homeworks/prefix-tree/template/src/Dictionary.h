#pragma once

#include <stdexcept>
#include <cctype> // Contains std::isalpha()
#include <cstring>

class incorrect_word_exception : public std::runtime_error {
public:
    incorrect_word_exception()
            : runtime_error("incorrect word")
    {
        // Nothing to do here
    }
};

class Dictionary {
public:
    Dictionary();
    ~Dictionary();

    void insert(const char* word);
    void erase(const char* word) noexcept;
    bool contains(const char* word) const noexcept;
    size_t size() const noexcept;
    static bool isCorrectWord(const char* word) noexcept;

private:
    struct Node {
        Node* children[26] = {nullptr};
        bool isEndOfWord = false;
    };

    Node* root;
    size_t wordCount;

    void clear(Node* node);
    bool eraseHelper(Node* node, const char* word);
    bool isEmptyNode(Node* node) const;
};


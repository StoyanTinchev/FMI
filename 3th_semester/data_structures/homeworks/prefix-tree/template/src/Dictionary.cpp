#include "Dictionary.h"

Dictionary::Dictionary() : root(new Node()), wordCount(0) {}

Dictionary::~Dictionary() {
    clear(root);
}

void Dictionary::clear(Node* node) {
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            clear(node->children[i]);
        }
    }
    delete node;
}

void Dictionary::insert(const char* word) {
    ++wordCount;

    if (!isCorrectWord(word)) {
        throw incorrect_word_exception();
    }

    Node* currentNode = root;
    while (*word) {
        char c = std::tolower(*word);
        int index = c - 'a';
        if (!currentNode->children[index]) {
            currentNode->children[index] = new Node();
        }
        currentNode = currentNode->children[index];
        word++;
    }
    if (!currentNode->isEndOfWord) {
        currentNode->isEndOfWord = true;
    }
}

void Dictionary::erase(const char* word) noexcept {
    if (!isCorrectWord(word)) {
        return;
    }

    eraseHelper(root, word);
}

bool Dictionary::eraseHelper(Node* node, const char* word) {
    if (!*word) {
        if (node->isEndOfWord) {
            node->isEndOfWord = false;
            --wordCount;
            return true;
        }
        return false;
    }

    char c = std::tolower(*word);
    int index = c - 'a';
    if (node->children[index] && eraseHelper(node->children[index], word + 1)) {
        if (isEmptyNode(node->children[index])) {
            delete node->children[index];
            node->children[index] = nullptr;
        }
        return !node->isEndOfWord && isEmptyNode(node);
    }
    return false;
}

bool Dictionary::isEmptyNode(Node* node) const {
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            return false;
        }
    }
    return true;
}

bool Dictionary::contains(const char* word) const noexcept {
    if (!isCorrectWord(word)) {
        return false;
    }

    Node* currentNode = root;
    while (*word) {
        char c = std::tolower(*word);
        int index = c - 'a';
        if (!currentNode->children[index]) {
            return false;
        }
        currentNode = currentNode->children[index];
        word++;
    }
    return currentNode->isEndOfWord;
}

size_t Dictionary::size() const noexcept {
    return wordCount;
}

bool Dictionary::isCorrectWord(const char* word) noexcept {
    if (!word || !*word) return false;
    while (*word) {
        if (!std::isalpha(*word)) {
            return false;
        }
        word++;
    }
    return true;
}

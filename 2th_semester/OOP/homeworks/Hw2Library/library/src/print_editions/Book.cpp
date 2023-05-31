#include "../../include/print_editions/Book.h"
#include <iostream>

Book::Book() : author(nullptr), publisher(nullptr) {}

Book::Book(const char *title,
           const char *shortDescription,
           int yearOfPublication,
           const char *author,
           const char *publisher,
           uint16_t genre)
        : PrintEdition(title, shortDescription, yearOfPublication),
          author(nullptr),
          publisher(nullptr),
          genre(genre) {
    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);

    this->publisher = new char[strlen(publisher) + 1];
    strcpy(this->publisher, publisher);
}

Book::~Book() {
    delete[] author;
    delete[] publisher;
}

const char *Book::getAuthor() const {
    return this->author;
}

void Book::setAuthor(const char *author) {
    delete[] this->author;
    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);
}

const char *Book::getPublisher() const {
    return this->publisher;
}

void Book::setPublisher(const char *publisher) {
    delete[] this->publisher;
    this->publisher = new char[strlen(publisher) + 1];
    strcpy(this->publisher, publisher);
}

uint16_t Book::getGenre() const {
    return this->genre;
}

void Book::setGenre(uint16_t genre) {
    this->genre = genre;
    updateGenreParityBit();
}

uint8_t Book::getGenreFeature() const {
    return genre & 0x7F;  // Get the lower 7 bits
}

void Book::setGenreFeature(uint8_t feature) {
    genre = (genre & 0xFF80) | (feature & 0x7F);
    updateGenreParityBit();
}

uint8_t Book::getGenreType() const {
    return (genre >> 7) & 0xF;  // Get the next 4 bits
}

void Book::setGenreType(uint8_t type) {
    genre = (genre & 0xF87F) | ((type & 0xF) << 7);
    updateGenreParityBit();
}

uint8_t Book::getGenreTargetAudience() const {
    return (genre >> 11) & 0xF;  // Get the next 4 bits
}

void Book::setGenreTargetAudience(uint8_t audience) {
    genre = (genre & 0x87FF) | ((audience & 0xF) << 11);
    updateGenreParityBit();
}

bool Book::getGenreParityBit() const {
    return (genre >> 15) & 0x1;  // Get the most significant bit
}

void Book::updateGenreParityBit() {
    uint16_t tempGenre = genre & 0x7FFF;  // Exclude the parity bit
    bool parity = 0;
    while (tempGenre) {
        parity = !parity;
        tempGenre = tempGenre & (tempGenre - 1);
    }
    genre = (genre & 0x7FFF) | (parity << 15);
}

const char *Book::getType() const {
    return "Book";
}

void Book::serialize(std::ofstream &ofs) const {
    PrintEdition::serialize(ofs);
    size_t authorLength = strlen(author);
    size_t publisherLength = strlen(publisher);
    ofs.write((char *) &authorLength, sizeof(authorLength));
    ofs.write(author, authorLength);
    ofs.write((char *) &publisherLength, sizeof(publisherLength));
    ofs.write(publisher, publisherLength);
    ofs.write((char *) &genre, sizeof(genre));
}

void Book::deserialize(std::ifstream &ifs) {
    PrintEdition::deserialize(ifs);

    size_t authorLength;
    ifs.read((char *) &authorLength, sizeof(authorLength));
    delete[] author;
    author = new char[authorLength + 1];
    ifs.read(author, authorLength);
    author[authorLength] = '\0';

    size_t publisherLength;
    ifs.read((char *) &publisherLength, sizeof(publisherLength));
    delete[] publisher;
    publisher = new char[publisherLength + 1];
    ifs.read(publisher, publisherLength);
    publisher[publisherLength] = '\0';

    ifs.read((char *) &genre, sizeof(genre));
}

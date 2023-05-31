#ifndef BOOK_H
#define BOOK_H

#include <cstdint>
#include <cstring>
#include <fstream>
#include "PrintEdition.h"

class Book : public virtual PrintEdition {
protected:
    char *author;
    char *publisher;
    uint16_t genre;  // 16-bit unsigned integer

public:
    Book();

    Book(const char *title,
         const char *shortDescription,
         int yearOfPublication,
         const char *author,
         const char *publisher,
         uint16_t genre);

    ~Book() override;

    const char *getAuthor() const;

    void setAuthor(const char *author);

    const char *getPublisher() const;

    void setPublisher(const char *publisher);

    uint16_t getGenre() const;

    void setGenre(uint16_t genre);

    uint8_t getGenreFeature() const;

    void setGenreFeature(uint8_t feature);

    uint8_t getGenreType() const;

    void setGenreType(uint8_t type);

    uint8_t getGenreTargetAudience() const;

    void setGenreTargetAudience(uint8_t audience);

    bool getGenreParityBit() const;

    void updateGenreParityBit();

    const char *getType() const override;

    void serialize(std::ofstream &ofs) const override;

    void deserialize(std::ifstream &ifs) override;
};

#endif // BOOK_H

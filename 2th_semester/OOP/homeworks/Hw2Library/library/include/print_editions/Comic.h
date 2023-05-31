#ifndef COMIC_H
#define COMIC_H

#include "Book.h"
#include "Periodical.h"

class Comic : public Book, public Periodical {
public:
    Comic();

    Comic(const char *title,
          const char *shortDescription,
          int yearOfPublication,
          const char *author,
          const char *publisher,
          uint16_t genre,
          Period period,
          int issue);

    ~Comic() override;

    const char *getType() const override;

    void serialize(std::ofstream &ofs) const override;

    void deserialize(std::ifstream &ifs) override;
};

#endif // COMIC_H

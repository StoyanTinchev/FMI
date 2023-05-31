#include "../../include/print_editions/Comic.h"
#include <iostream>

Comic::Comic(const char *title,
             const char *shortDescription,
             int yearOfPublication,
             const char *author,
             const char *publisher,
             uint16_t genre,
             Period period,
             int issue)
        : PrintEdition(title, shortDescription, yearOfPublication),
          Book(title, shortDescription, yearOfPublication, author, publisher, genre),
          Periodical(title, shortDescription, yearOfPublication, period, issue) {}

Comic::~Comic() = default;

const char *Comic::getType() const {
    return "Comic";
}

#include "../../include/print_editions/Comic.h"

Comic::Comic() {}

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

void Comic::serialize(std::ofstream &ofs) const {
    PrintEdition::serialize(ofs);
    size_t authorLength = strlen(author);
    size_t publisherLength = strlen(publisher);
    ofs.write((char *) &authorLength, sizeof(authorLength));
    ofs.write(author, authorLength);
    ofs.write((char *) &publisherLength, sizeof(publisherLength));
    ofs.write(publisher, publisherLength);
    ofs.write((char *) &genre, sizeof(genre));
    ofs.write((char *) &period, sizeof(period));
    ofs.write((char *) &issue, sizeof(issue));
}

void Comic::deserialize(std::ifstream &ifs) {
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
    ifs.read((char *) &period, sizeof(period));
    ifs.read((char *) &issue, sizeof(issue));
}

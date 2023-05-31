#include "../../include/print_editions/PrintEdition.h"

int PrintEdition::nextLibraryNumber = 1;

PrintEdition::PrintEdition(const char *title,
                           const char *shortDescription,
                           int yearOfPublication)
        : libraryNumber(nextLibraryNumber),
          yearOfPublication(yearOfPublication) {

    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    this->shortDescription = new char[strlen(shortDescription) + 1];
    strcpy(this->shortDescription, shortDescription);
}

PrintEdition::~PrintEdition() {
    delete[] title;
    delete[] shortDescription;
}

const char *PrintEdition::getTitle() const {
    return this->title;
}

int PrintEdition::getLibraryNumber() const {
    return this->libraryNumber;
}

int PrintEdition::getYearOfPublication() const {
    return this->yearOfPublication;
}

std::ostream &operator<<(std::ostream &os, const PrintEdition &edition) {
    os << "Title: " << edition.title
       << "\nType: " << edition.getType()
       << "\nShortDescription: " << edition.shortDescription
       << "\nLibraryNumber: " << edition.libraryNumber;
    return os;
}

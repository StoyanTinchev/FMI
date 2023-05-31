#include "../../include/print_editions/PrintEdition.h"

int PrintEdition::nextLibraryNumber = 1;

PrintEdition::PrintEdition() : title(nullptr), shortDescription(nullptr) {}

PrintEdition::PrintEdition(const char *title,
                           const char *shortDescription,
                           int yearOfPublication)
        : libraryNumber(nextLibraryNumber++),
          yearOfPublication(yearOfPublication),
          title(nullptr),
          shortDescription(nullptr) {

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

void PrintEdition::serialize(std::ofstream &ofs) const {
    size_t typeLength = strlen(getType());
    ofs.write(reinterpret_cast<const char *>(&typeLength), sizeof(typeLength));
    ofs.write(getType(), typeLength);

    ofs.write(reinterpret_cast<const char *>(&libraryNumber), sizeof(libraryNumber));
    ofs.write(reinterpret_cast<const char *>(&yearOfPublication), sizeof(yearOfPublication));

    size_t titleLength = strlen(title);
    ofs.write(reinterpret_cast<const char *>(&titleLength), sizeof(titleLength));
    ofs.write(title, titleLength);

    size_t descriptionLength = strlen(shortDescription);
    ofs.write(reinterpret_cast<const char *>(&descriptionLength), sizeof(descriptionLength));
    ofs.write(shortDescription, descriptionLength);
}

void PrintEdition::deserialize(std::ifstream &ifs) {
    ifs.read(reinterpret_cast<char *>(&libraryNumber), sizeof(libraryNumber));
    ifs.read(reinterpret_cast<char *>(&yearOfPublication), sizeof(yearOfPublication));

    size_t titleLength;
    ifs.read(reinterpret_cast<char *>(&titleLength), sizeof(titleLength));
    delete[] title;
    title = new char[titleLength + 1];
    ifs.read(title, titleLength);
    title[titleLength] = '\0';

    size_t descriptionLength;
    ifs.read(reinterpret_cast<char *>(&descriptionLength), sizeof(descriptionLength));
    delete[] shortDescription;
    shortDescription = new char[descriptionLength + 1];
    ifs.read(shortDescription, descriptionLength);
    shortDescription[descriptionLength] = '\0';
}

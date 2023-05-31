#ifndef PRINT_EDITION_H
#define PRINT_EDITION_H

#include <cstring>
#include <ostream>
#include <fstream>

class PrintEdition {
protected:
    char *title;
    char *shortDescription;
    int libraryNumber;
    int yearOfPublication;

    static int nextLibraryNumber;

    PrintEdition();

    PrintEdition(const char *title,
                 const char *shortDescription,
                 int yearOfPublication);

public:
    virtual ~PrintEdition() = 0;

    const char *getTitle() const;

    int getLibraryNumber() const;

    int getYearOfPublication() const;

    friend std::ostream &operator<<(std::ostream &os, const PrintEdition &edition);

    virtual const char *getType() const = 0;

    virtual void serialize(std::ofstream &ofs) const;

    virtual void deserialize(std::ifstream &ifs);

private:
    PrintEdition(const PrintEdition &other);

    PrintEdition &operator=(const PrintEdition &other);
};

#endif // PRINT_EDITION_H

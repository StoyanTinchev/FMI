#ifndef USER_H
#define USER_H


#include <ostream>
#include "../print_editions/PrintEdition.h"
#include "ctime"
#include "../Library.h"

struct Loan {
    PrintEdition *edition;
    std::tm loanDate;
};

class Library;

class User {
private:
    char *name;

    Loan **currentlyReading;
    int currentlyReadingCount;
    int currentlyReadingCapacity;

    PrintEdition **read;
    int readCount;
    int readCapacity;

    // add and remove print publications from the currently read list
    void startReading(PrintEdition *edition);

    void finishReading(PrintEdition *edition);

    void resizeCurrentlyReading();

    void resizeRead();

    void copy(const User &other);

    void erase();

public:
    User();

    explicit User(const char *name);

    User(const User &other);

    const char *getName() const;

    void setName(char *name);

    User &operator=(const User &other);

    ~User();

    // check whether edition loan is overdue
    bool isOverdue(int loanIndex) const;

    // gets loan by index
    const Loan *getLoan(int idx) const;

    // literally returns the "readCount" variable
    int getNumberOfReadEditions() const;

    // literally returns the "currentlyReadingCount" variable
    int getCurrentlyReadingCount() const;

    // returns whether is READING edition with the corresponding "libraryNumber" or not
    bool isReadingEdition(int libraryNumber) const;

    // returns whether is READ the edition with the corresponding "libraryNumber" or not
    bool hasReadEdition(int libraryNumber) const;

    // comparison operators
    bool operator==(const User &other) const;

    bool operator!=(const User &other) const;

    bool operator<(const User &other) const;

    bool operator<=(const User &other) const;

    bool operator>(const User &other) const;

    bool operator>=(const User &other) const;

    // issue loan and return operators
    User operator+(PrintEdition *edition);

    User &operator+=(PrintEdition *edition);

    User operator-(PrintEdition *edition);

    User &operator-=(PrintEdition *edition);

    // indexing operator
    PrintEdition *operator[](int libraryNumber);

    friend std::ostream &operator<<(std::ostream &os, const User &user);

    void serialize(std::ofstream &ofs) const;

    void deserialize(std::ifstream &ifs, Library &library);
};

#endif // USER_H

#ifndef LIBRARY_H
#define LIBRARY_H


#include "print_editions/PrintEdition.h"
#include "user/User.h"

class User;

class Library {
private:
    PrintEdition **editions;
    int editionsCount;
    int editionsCapacity;

    User **users;
    int usersCount;
    int usersCapacity;

public:
    Library();

    ~Library();

    void addEdition(PrintEdition *edition);

    void removeEdition(int libraryNumber);

    void displayEditions() const;

    void addUser(User *user);

    void removeUser(const char *name);

    void displayOverdueEditions() const;

    void displayUsersWithBook(int libraryNumber) const;

    void displayUsersByReadCount() const;

    void lendEdition(const char *userName, int libraryNumber) const;

    void returnEdition(const char *userName, int libraryNumber) const;

    void saveToFile(const char *editionsFileName, const char *usersFileName);

    void loadFromFile(const char *editionsFileName, const char *usersFileName);

    PrintEdition *getPrintEditionByLibraryNumber(int libraryNumber);

private:
    void resizeEditions();

    void resizeUsers();
};

#endif

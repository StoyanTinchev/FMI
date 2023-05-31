#include "../include/Library.h"
#include "../include/utility.h"
#include "../include/print_editions/Periodical.h"
#include "../include/print_editions/Book.h"
#include "../include/print_editions/Comic.h"
#include <iostream>

Library::Library() : editions(nullptr), users(nullptr) {
    this->editionsCount = 0;
    this->editionsCapacity = 4;
    this->editions = new PrintEdition *[this->editionsCapacity];

    this->usersCount = 0;
    this->usersCapacity = 4;
    this->users = new User *[this->usersCapacity];
}

Library::~Library() {
    for (int i = 0; i < this->editionsCount; ++i) {
        delete this->editions[i];
    }
    delete[] this->editions;

    for (int i = 0; i < this->usersCount; ++i) {
        delete this->users[i];
    }
    delete[] this->users;
}

void Library::addEdition(PrintEdition *edition) {
    if (this->editionsCount == this->editionsCapacity) {
        this->resizeEditions();
    }
    this->editions[this->editionsCount++] = edition;
    std::cout << "Added edition with library number " << edition->getLibraryNumber() << std::endl;
}

void Library::removeEdition(int libraryNumber) {
    bool success = false;
    for (int i = 0; i < this->editionsCount; ++i) {
        if (this->editions[i]->getLibraryNumber() == libraryNumber) {
            delete this->editions[i];

            this->editions[i] = this->editions[this->editionsCount - 1];
            --this->editionsCount;
            success = true;
            break;
        }
    }
    if (!success)
        throw std::invalid_argument("Edition with library number " + std::to_string(libraryNumber) + " not found");

    std::cout << "Successfully removed edition with library number " << libraryNumber << std::endl;
}

void Library::displayEditions() const {
    selectionSort(this->editions, this->editionsCount,
                  [](const PrintEdition *a, const PrintEdition *b) {
                      if (a->getYearOfPublication() != b->getYearOfPublication()) {
                          return a->getYearOfPublication() < b->getYearOfPublication();
                      } else if (a->getTitle() != b->getTitle()) {
                          return a->getTitle() < b->getTitle();
                      } else {
                          // When titles are same, and they are periodicals, sort by issue number
                          auto periodical_a = dynamic_cast<const Periodical *>(a);
                          auto periodical_b = dynamic_cast<const Periodical *>(b);
                          if (periodical_a && periodical_b) {
                              return periodical_a->getIssue() < periodical_b->getIssue();
                          }
                          // If they are not periodicals or only one of them is, keep their original order
                          return false;
                      }
                  });

    for (int i = 0; i < this->editionsCount; ++i) {
        std::cout << *this->editions[i] << std::endl;
    }
}

void Library::addUser(User *user) {
    if (this->usersCount == this->usersCapacity) {
        this->resizeUsers();
    }
    this->users[this->usersCount++] = user;
    std::cout << "User " << user->getName() << " registered successfully in the library" << std::endl;
}

void Library::removeUser(const char *name) {
    std::cout << "User " << name;
    bool success = false;
    for (int i = 0; i < this->usersCount; ++i) {
        if (strcmp(this->users[i]->getName(), name) == 0) {
            delete this->users[i];

            this->users[i] = this->users[this->usersCount - 1];
            --this->usersCount;
            success = true;
            break;
        }
    }
    if (!success)
        throw std::invalid_argument(" not found");

    std::cout << " successfully removed from the library" << std::endl;
}

void Library::displayOverdueEditions() const {
    // first, we'll get all overdue editions
    int overdueCount = 0;
    int overdueCapacity = 2;
    const Loan **overdueEditions = new const Loan *[overdueCapacity];

    for (int i = 0; i < this->usersCount; ++i) {
        User *user = this->users[i];
        for (int j = 0; j < user->getCurrentlyReadingCount(); ++j) {
            if (user->isOverdue(j)) {
                if (overdueCount >= overdueCapacity) {
                    resize(overdueEditions, overdueCount, overdueCapacity);
                }
                overdueEditions[overdueCount++] = user->getLoan(j);
            }
        }
    }

    // now, we sort the overdue editions by year and title
    selectionSort(overdueEditions, overdueCount, [](const Loan *a, const Loan *b) -> bool {
        PrintEdition *aEdition = a->edition;
        PrintEdition *bEdition = b->edition;

        // first by year
        if (aEdition->getYearOfPublication() != bEdition->getYearOfPublication()) {
            return aEdition->getYearOfPublication() < bEdition->getYearOfPublication();
        }

        // then by title
        return strcmp(aEdition->getTitle(), bEdition->getTitle()) < 0;
    });

    // finally, we display them
    for (int i = 0; i < overdueCount; ++i) {
        std::cout << overdueEditions[i]->edition << std::endl;
    }

    // clean up
    delete[] overdueEditions;
}

void Library::displayUsersWithBook(int libraryNumber) const {
    for (int i = 0; i < this->usersCount; ++i) {
        if (this->users[i]->isReadingEdition(libraryNumber)) {
            std::cout << *this->users[i] << std::endl;
        }
    }
}

void Library::displayUsersByReadCount() const {
    User **usersCopy = new User *[this->usersCount];
    for (int i = 0; i < this->usersCount; ++i) {
        usersCopy[i] = this->users[i];
    }

    // Use the utility function to sort the array
    selectionSort(usersCopy, this->usersCount, [](User *a, User *b) -> bool {
        return a->getNumberOfReadEditions() > b->getNumberOfReadEditions();
    });

    std::cout << std::endl;
    for (int i = 0; i < this->usersCount; ++i) {
        std::cout << *usersCopy[i] << std::endl;
    }
    std::cout << std::endl;

    delete[] usersCopy;
}

void Library::resizeEditions() {
    resize(this->editions, this->editionsCount, this->editionsCapacity);
}

void Library::resizeUsers() {
    resize(this->users, this->usersCount, this->usersCapacity);
}

void Library::lendEdition(const char *userName, int libraryNumber) const {
    User *user = nullptr;
    PrintEdition *edition = nullptr;

    // find the user
    for (int i = 0; i < this->usersCount; ++i) {
        if (strcmp(this->users[i]->getName(), userName) == 0) {
            user = this->users[i];
            break;
        }
    }

    // find the edition
    for (int i = 0; i < this->editionsCount; ++i) {
        if (this->editions[i]->getLibraryNumber() == libraryNumber) {
            edition = this->editions[i];
            break;
        }
    }

    // if we didn't find the user
    if (!user)
        throw std::invalid_argument("Incorrect user. The edition isn't lent.");


    // if we didn't find the edition
    if (!edition)
        throw std::invalid_argument("Incorrect edition. The edition isn't lent.");


    // the user does not already have this edition
    if ((*user)[libraryNumber] != nullptr)
        throw std::invalid_argument("The user already has this edition.");

    *user += edition;
    std::cout << "User " << user->getName() << " successfully lent " << edition->getTitle() << std::endl;
}

void Library::returnEdition(const char *userName, int libraryNumber) const {
    User *user = nullptr;
    PrintEdition *edition = nullptr;

    // find the user
    for (int i = 0; i < this->usersCount; ++i) {
        if (strcmp(this->users[i]->getName(), userName) == 0) {
            user = this->users[i];
            break;
        }
    }

    // find the edition
    for (int i = 0; i < this->editionsCount; ++i) {
        if (this->editions[i]->getLibraryNumber() == libraryNumber) {
            edition = this->editions[i];
            break;
        }
    }

    // if we didn't find the user
    if (!user)
        throw std::invalid_argument("Incorrect user. The edition isn't returned.");

    // if we didn't find the edition
    if (!edition)
        throw std::invalid_argument("Incorrect edition. The edition isn't returned.");

    *user -= edition;
    std::cout << "User " << user->getName() << " successfully returned " << edition->getTitle() << std::endl;
}

void Library::saveToFile(const char *editionsFileName, const char *usersFileName) {
    std::ofstream editionsFile(editionsFileName, std::ios::binary | std::ios::out);

    if (!editionsFile) {
        std::cerr << "Couldn't open file for writing: " << editionsFileName << std::endl;
        return;
    }

    // Save editions
    for (int i = 0; i < editionsCount; i++) {
        PrintEdition *edition = editions[i];
        edition->serialize(editionsFile);
    }

    editionsFile.close();


    std::ofstream usersFile(usersFileName, std::ios::binary | std::ios::out);

    if (!usersFile) {
        std::cerr << "Couldn't open file for writing: " << usersFileName << std::endl;
        return;
    }

    // Save users
    for (int i = 0; i < usersCount; i++) {
        User *user = users[i];
        user->serialize(usersFile);
    }

    usersFile.close();
}


void Library::loadFromFile(const char *editionsFileName, const char *usersFileName) {
    std::ifstream editionsFile(editionsFileName, std::ios::binary | std::ios::in);

    if (!editionsFile) {
        std::cerr << "Couldn't open file for reading: " << editionsFileName << std::endl;
        return;
    }

    // Clear current data
    for (int i = 0; i < editionsCount; i++) {
        delete editions[i];
    }
    editionsCount = 0;

    for (int i = 0; i < usersCount; i++) {
        delete users[i];
    }
    usersCount = 0;

    // Load editions
    while (!editionsFile.eof()) {
        size_t typeLength;
        editionsFile.read(reinterpret_cast<char *>(&typeLength), sizeof(typeLength));
        char *type = new char[typeLength + 1];
        editionsFile.read(type, typeLength);
        type[typeLength] = '\0';
        if (editionsFile.eof()) {
            delete[] type;
            break;
        }

        PrintEdition *edition = nullptr;

        if (strcmp(type, "Book") == 0) {
            edition = new Book();
        } else if (strcmp(type, "Comic") == 0) {
            edition = new Comic();
        } else if (strcmp(type, "Periodical") == 0) {
            edition = new Periodical();
        }

        if (edition) {
            edition->deserialize(editionsFile);
            addEdition(edition);
        }
        delete[] type;
    }

    editionsFile.close();


    std::ifstream usersfile(usersFileName, std::ios::binary | std::ios::in);

    if (!usersfile) {
        std::cerr << "Couldn't open file for reading: " << usersFileName << std::endl;
        return;
    }

    // Load users
    while (!usersfile.eof()) {
        User *user = new User();
        user->deserialize(usersfile, *this);
        if (usersfile.eof()) break;
        addUser(user);
    }

    usersfile.close();
}

PrintEdition *Library::getPrintEditionByLibraryNumber(int libraryNumber) {
    for (int i = 0; i < editionsCount; i++) {
        if (editions[i]->getLibraryNumber() == libraryNumber) {
            return editions[i];
        }
    }

    return nullptr; // Return null if no edition with the given libraryNumber is found
}

#include "../../include/user/User.h"
#include "../../include/utility.h"

User::User(const char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->currentlyReadingCount = 0;
    this->readCount = 0;
    this->currentlyReadingCapacity = 2;
    this->readCapacity = 2;

    this->currentlyReading = new Loan *[this->currentlyReadingCapacity];
    this->read = new PrintEdition *[this->readCapacity];
}

User::User(const User &other) {
    copy(other);
}

User &User::operator=(const User &other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}

User::~User() {
    erase();
}

bool User::isOverdue(int loanIndex) const {
    time_t now = time(nullptr);
    double difference = difftime(now, mktime(&this->currentlyReading[loanIndex]->loanDate));
    return difference > (30 * 24 * 60 * 60); // More than 30 days
}

const Loan * User::getLoan(int idx) const {
    if (idx < 0 || idx >= this->currentlyReadingCount) {
        return nullptr;
    }
    return this->currentlyReading[idx];
}

int User::getNumberOfReadEditions() const {
    return readCount;
}

bool User::isReadingEdition(int libraryNumber) const {
    for (int i = 0; i < this->currentlyReadingCount; i++) {
        if (this->currentlyReading[i]->edition->getLibraryNumber() == libraryNumber) {
            return true;
        }
    }
    return false;
}

bool User::hasReadEdition(int libraryNumber) const {
    for (int i = 0; i < this->readCount; i++) {
        if (this->read[i]->getLibraryNumber() == libraryNumber) {
            return true;
        }
    }
    return false;
}

bool User::operator==(const User &other) const {
    return strcmp(this->name, other.name) == 0;
}

bool User::operator!=(const User &other) const {
    return !(*this == other);
}

bool User::operator<(const User &other) const {
    return this->readCount < other.readCount;
}

bool User::operator<=(const User &other) const {
    return !(*this > other);
}

bool User::operator>(const User &other) const {
    return other < *this;
}

bool User::operator>=(const User &other) const {
    return !(*this < other);
}

User User::operator+(PrintEdition *edition) {
    User newUser = *this;
    newUser.startReading(edition);
    return newUser;
}

User &User::operator+=(PrintEdition *edition) {
    this->startReading(edition);
    return *this;
}

User User::operator-(PrintEdition *edition) {
    User newUser = *this;
    newUser.finishReading(edition);
    return newUser;
}

User &User::operator-=(PrintEdition *edition) {
    this->finishReading(edition);
    return *this;
}

PrintEdition *User::operator[](int libraryNumber) {
    for (int i = 0; i < this->currentlyReadingCount; i++) {
        if (this->currentlyReading[i]->edition->getLibraryNumber() == libraryNumber) {
            return this->currentlyReading[i]->edition;
        }
    }
    for (int i = 0; i < this->readCount; i++) {
        if (this->read[i]->getLibraryNumber() == libraryNumber) {
            return this->read[i];
        }
    }
    return nullptr;
}

void User::startReading(PrintEdition *edition) {
    if (this->currentlyReadingCount >= this->currentlyReadingCapacity) {
        resizeCurrentlyReading();
    }
    this->currentlyReading[this->currentlyReadingCount] = new Loan;
    this->currentlyReading[this->currentlyReadingCount]->edition = edition;
    time_t now = time(nullptr);
    this->currentlyReading[this->currentlyReadingCount]->loanDate = *localtime(&now);
    this->currentlyReadingCount++;
}

void User::finishReading(PrintEdition *edition) {
    int index = -1;
    for (int i = 0; i < this->currentlyReadingCount; i++) {
        if (this->currentlyReading[i]->edition == edition) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        delete this->currentlyReading[index];
        for (int i = index; i < this->currentlyReadingCount - 1; i++) {
            this->currentlyReading[i] = this->currentlyReading[i + 1];
        }
        this->currentlyReadingCount--;

        if (this->readCount >= this->readCapacity) {
            resizeRead();
        }
        this->read[this->readCount++] = edition;
    }
}

void User::resizeCurrentlyReading() {
    resize(this->currentlyReading, this->currentlyReadingCount, this->currentlyReadingCapacity);
}

void User::resizeRead() {
    resize(this->read, this->readCount, this->readCapacity);
}

void User::copy(const User &other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->currentlyReadingCount = other.currentlyReadingCount;
    this->readCount = other.readCount;
    this->currentlyReadingCapacity = other.currentlyReadingCapacity;
    this->readCapacity = other.readCapacity;

    this->currentlyReading = new Loan *[this->currentlyReadingCapacity];
    for (int i = 0; i < this->currentlyReadingCount; i++) {
        this->currentlyReading[i] = new Loan(*other.currentlyReading[i]);
    }

    this->read = new PrintEdition *[this->readCapacity];
    for (int i = 0; i < this->readCount; i++) {
        this->read[i] = other.read[i];
    }
}

void User::erase() {
    delete[] this->name;
    for (int i = 0; i < this->currentlyReadingCount; ++i) {
        delete this->currentlyReading[i];
    }
    delete[] this->currentlyReading;
    delete[] this->read;
}

const char * User::getName() const {
    return name;
}

void User::setName(char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "name: " << user.name;
    return os;
}

int User::getCurrentlyReadingCount() const {
    return currentlyReadingCount;
}

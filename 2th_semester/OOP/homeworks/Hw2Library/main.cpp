#include <iostream>
#include "library/include/print_editions/Book.h"
#include "library/include/print_editions/Periodical.h"
#include "library/include/print_editions/Comic.h"
#include "library/include/Library.h"

int main() {
    Book *book1 = new Book("FirstBook", "First book short description", 2001, "first book author",
                           "first book publisher", 1);
    Book *book2 = new Book("SecondBook", "Second book short description", 2002, "second book author",
                           "second book publisher", 2);

    Periodical *periodical1 = new Periodical("FirstPeriodical", "First periodical short description",
                                             2003, Weekly, 1);
    Periodical *periodical2 = new Periodical("SecondPeriodical", "Second periodical short description",
                                             2004, Monthly, 2);

    Comic *comic1 = new Comic("FirstComic", "First comic short description", 2005, "first comic author",
                              "first comic publisher", 3, Weekly, 1);
    Comic *comic2 = new Comic("SecondComic", "Second comic short description", 2006, "second comic author",
                              "second comic publisher", 4, Monthly, 2);

    Library *library = new Library();

    library->addEdition(book1);
    library->addEdition(book2);
    library->addEdition(periodical1);
    library->addEdition(periodical2);
    library->addEdition(comic1);
    library->addEdition(comic2);

    User *user1 = new User("Pesho");
    User *user2 = new User("Gosho");
    User *user3 = new User("Tosho");
    library->addUser(user1);
    library->addUser(user2);
    library->addUser(user3);

    library->saveToFile("editionsFile.dat", "usersFile.dat");

    delete library; // Delete old library to ensure data is actually loaded from the file

    Library *newLibrary = new Library();
    newLibrary->loadFromFile(
            "/Users/with/Desktop/FMI/2th_semester/OOP/homeworks/Hw2Library/cmake-build-debug/editionsFile.dat",
            "/Users/with/Desktop/FMI/2th_semester/OOP/homeworks/Hw2Library/cmake-build-debug/usersFile.dat");

    newLibrary->lendEdition("Pesho", 1);
    newLibrary->lendEdition("Gosho", 1);
    newLibrary->lendEdition("Tosho", 3);

    newLibrary->returnEdition("Pesho", 1);

    newLibrary->displayOverdueEditions();

    newLibrary->displayUsersWithBook(1);

    newLibrary->displayUsersByReadCount();

    newLibrary->removeEdition(2);
    newLibrary->removeEdition(4);

    newLibrary->displayEditions();

    newLibrary->removeUser("Tosho");

    delete newLibrary;
    return 0;
}

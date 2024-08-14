#include "student.h"

Student::Student(int id, int arrivalTime, Specialty specialty, int enthusiasm)
        : id(id), arrivalTime(arrivalTime), specialty(specialty), enthusiasm(enthusiasm) {}

int Student::getId() const {
    return id;
}

int Student::getArrivalTime() const {
    return arrivalTime;
}

Specialty Student::getSpecialty() const {
    return specialty;
}

int Student::getEnthusiasm() const {
    return enthusiasm;
}

#pragma once

#include "student.h"
#include <list>

class Group {
public:
    Group(Specialty specialty);

    void addStudent(const Student &student);

    Specialty getSpecialty() const;

    const std::list<Student> &getStudents() const;

    int size() const;

    int getEarliestArrivalTime() const;

private:
    Specialty specialty;
    std::list<Student> students;
};

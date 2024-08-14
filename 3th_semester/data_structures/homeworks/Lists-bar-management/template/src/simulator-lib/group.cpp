#include "group.h"

Group::Group(Specialty specialty) : specialty(specialty) {}

void Group::addStudent(const Student &student) {
    if (student.getSpecialty() == specialty) {
        students.push_back(student);
    }
}

Specialty Group::getSpecialty() const {
    return specialty;
}

const std::list<Student> &Group::getStudents() const {
    return students;
}

int Group::size() const {
    return students.size();
}

int Group::getEarliestArrivalTime() const {
    if (!students.empty()) {
        return students.front().getArrivalTime();
    }
    return std::numeric_limits<int>::max();
}
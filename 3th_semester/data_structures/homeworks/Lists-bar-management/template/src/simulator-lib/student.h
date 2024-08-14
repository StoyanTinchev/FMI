#pragma once

#include <string>

enum class Specialty {
    Fraud,
    InternationalSchemes,
    CreativeNihilism,
    SubjectiveResearches,
    FileAnalysis,
    Micromanagement,
    AppliedMaterialization,
    Subjectivistics,
    MagnetismAndClearing
};

class Student {
public:
    Student(int id, int arrivalTime, Specialty specialty, int enthusiasm);

    int getId() const;

    int getArrivalTime() const;

    Specialty getSpecialty() const;

    int getEnthusiasm() const;

private:
    int id;
    int arrivalTime;
    Specialty specialty;
    int enthusiasm;
};

#include "bar-simulator.h"
#include "bar.h"
#include "group.h"
#include "student.h"
#include <queue>
#include <unordered_map>

// Функция за преобразуване на стринг в Specialty enum
Specialty stringToSpecialty(const std::string &str) {
    static const std::unordered_map<std::string, Specialty> specialtyMap = {
            {"Fraud", Specialty::Fraud},
            {"InternationalSchemes", Specialty::InternationalSchemes},
            {"CreativeNihilism", Specialty::CreativeNihilism},
            {"SubjectiveResearches", Specialty::SubjectiveResearches},
            {"FileAnalizis", Specialty::FileAnalysis},
            {"Micromanagement", Specialty::Micromanagement},
            {"AppliedMaterialization", Specialty::AppliedMaterialization},
            {"Subjectivistics", Specialty::Subjectivistics},
            {"MagnetismAndClearing", Specialty::MagnetismAndClearing}
    };

    auto it = specialtyMap.find(str);
    if (it != specialtyMap.end()) {
        return it->second;
    }
    throw incorrect_simulation("Invalid specialty: " + str);
}

void simulate_bar(std::istream &input, std::ostream &output) {
    int K, G, N;
    input >> K >> G >> N;

    Bar bar(K);
    std::queue<Group> queue;

    int currentTime = 0;
    for (int i = 0; i < N; ++i) {
        int studentId, arrivalTime, enthusiasm;
        std::string specialtyStr;
        input >> studentId >> arrivalTime >> specialtyStr >> enthusiasm;

        Specialty specialty = stringToSpecialty(specialtyStr);
        Student student(studentId, arrivalTime, specialty, enthusiasm);

        // Добавяне на студента в съответната група или създаване на нова група
        if (!queue.empty() && queue.back().getSpecialty() == specialty) {
            queue.back().addStudent(student);
        } else {
            Group newGroup(specialty);
            newGroup.addStudent(student);
            queue.push(newGroup);
        }

        // Проверка и обработка на студентите в бара и опашката
        while (!queue.empty() || !bar.isEmpty()) {
            // Обновяване на времето
            if (!queue.empty()) {
                currentTime = std::max(currentTime, queue.front().getEarliestArrivalTime());
            }

            // Извеждане на студенти от бара
            while (!bar.isEmpty() && bar.nextDepartureTime() <= currentTime) {
                int studentId = bar.depart();
                output << currentTime << " " << studentId << " exit\n";
            }

            // Влизане на групи в бара
            while (!queue.empty() && bar.getAvailableCapacity() >= queue.front().size()) {
                Group &group = queue.front();
                bar.enter(group);
                for (const Student &student: group.getStudents()) {
                    output << currentTime << " " << student.getId() << " enter\n";
                }
                queue.pop();
            }

            // Актуализация на времето за следващия цикъл
            currentTime++;
        }
    }
}

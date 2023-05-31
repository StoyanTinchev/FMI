#include "../../include/print_editions/Periodical.h"

Periodical::Periodical() {}

Periodical::Periodical(const char *title,
                       const char *shortDescription,
                       int yearOfPublication,
                       Period period,
                       int issue)
        : PrintEdition(title, shortDescription, yearOfPublication),
          period(period),
          issue(issue) {}

Periodical::~Periodical() = default;

Period Periodical::getPeriod() const {
    return this->period;
}

void Periodical::setPeriod(Period period) {
    this->period = period;
}

int Periodical::getIssue() const {
    return this->issue;
}

void Periodical::setIssue(int issue) {
    this->issue = issue;
}

const char *Periodical::getType() const {
    return "Periodical";
}

void Periodical::serialize(std::ofstream &ofs) const {
    PrintEdition::serialize(ofs);
    ofs.write((char *) &period, sizeof(period));
    ofs.write((char *) &issue, sizeof(issue));
}

void Periodical::deserialize(std::ifstream &ifs) {
    PrintEdition::deserialize(ifs);
    ifs.read((char *) &period, sizeof(period));
    ifs.read((char *) &issue, sizeof(issue));
}

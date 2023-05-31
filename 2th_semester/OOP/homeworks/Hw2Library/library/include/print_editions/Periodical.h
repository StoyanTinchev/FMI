#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <fstream>
#include "PrintEdition.h"

enum Period {
    Weekly, Monthly, Yearly
};

class Periodical : public virtual PrintEdition {
protected:
    Period period;
    int issue;

public:
    Periodical();

    Periodical(const char *title,
               const char *shortDescription,
               int yearOfPublication,
               Period period,
               int issue);

    ~Periodical() override;

    Period getPeriod() const;

    void setPeriod(Period period);

    int getIssue() const;

    void setIssue(int issue);

    const char *getType() const override;

    void serialize(std::ofstream &ofs) const override;

    void deserialize(std::ifstream &ifs) override;
};

#endif // PERIODICAL_H

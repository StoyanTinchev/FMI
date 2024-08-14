#pragma once

#include <istream>
#include <exception>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

struct Operation {
    char symbol;
    char operation; // '+', '-', '*', or '/'
    int priority;
    char associativity; // 'L' or 'R'
};

class OperationSet {
private:
    std::vector<Operation> operations;

public:
    void addOperation(const Operation &op);

    const Operation *getOperation(char symbol) const;
};

// An exception that is thrown by evaluate when it detects an incorrect expression
class incorrect_expression : public std::invalid_argument {
public:
    incorrect_expression(const std::string &what_arg)
            : invalid_argument(what_arg) {
        // Nothing to do here        
    }
};

double evaluate(const char *expression, std::istream &ops);

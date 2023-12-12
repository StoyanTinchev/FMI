#include "solution.h"

#include <cassert>
#include <stdexcept>
#include <stack>
#include <string>

bool verify(const std::string &expression) {
    if (expression.empty())
        return true;

    if (isOperation(expression[0]) || isOperation(expression[expression.length() - 1]))
        return false;

    char prevChar;
    for (char curr: expression) {
        if (curr == ' ' || !(isDigit(curr) || isOperation(curr)))
            return false;

        if (isDigit(curr) && isDigit(prevChar))
            return false;

        if (isOperation(curr) && isOperation(prevChar))
            return false;

        prevChar = curr;
    }

    return true;
}

std::string toRpn(const std::string &expression, Associativity associativity) {
    if (expression.empty())
        return expression;

    if (!verify(expression))
        throw std::invalid_argument("Invalid expression");

    std::stack<const char> operations;
    std::string result;

    for (const char curr: expression) {
        if (isDigit(curr)) {
            result += curr;
            continue;
        }

        assert(isOperation(curr));
        if (operations.empty()) {
            operations.push(curr);
            continue;
        }

        if (priority(curr) < priority(operations.top())) {
            if (associativity == Associativity::Right) {
                while (!operations.empty() && (priority(curr) < priority(operations.top()))) {
                    result += operations.top();
                    operations.pop();
                }
                operations.push(curr);
                continue;
            }

            while (!operations.empty() && (priority(curr) <=
                                           priority(operations.top()))) {
                result += operations.top();
                operations.pop();
            }
            operations.push(curr);
            continue;
        }

        if (priority(curr) == priority(operations.top())) {
            if (associativity == Associativity::Left) {
                result += operations.top();
                operations.pop();
                operations.push(curr);
            } else
                operations.push(curr);
            continue;
        }

        operations.push(curr);
    }

    while (!operations.empty()) {
        result += operations.top();
        operations.pop();
    }

    return result;
}

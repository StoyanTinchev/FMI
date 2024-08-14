#pragma once

#include <string>
#include <stack>
#include "expression.h"

class InfixToPostfixConverter {
public:
    static std::vector<std::string> convert(const std::vector<std::string>& tokens, const OperationSet& opSet);

private:
    static bool hasHigherPrecedence(const std::string& op1, const std::string& op2, const OperationSet& opSet);
};

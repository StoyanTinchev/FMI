#include "infix_to_postfix_converter.h"

std::vector<std::string>
InfixToPostfixConverter::convert(const std::vector<std::string> &tokens, const OperationSet &opSet) {
    std::stack<std::string> stack;
    std::vector<std::string> postfix;

    for (const auto &token: tokens) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            postfix.push_back(token);
        } else if (token == "(") {
            stack.push(token);
        } else if (token == ")") {
            while (!stack.empty() && stack.top() != "(") {
                postfix.push_back(stack.top());
                stack.pop();
            }
            if (!stack.empty()) {
                stack.pop();
            } else {
                throw incorrect_expression("Mismatched parentheses");
            }
        } else {
            while (!stack.empty() && stack.top() != "(" &&
                   hasHigherPrecedence(stack.top(), token, opSet)) {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(token);
        }
    }

    while (!stack.empty()) {
        if (stack.top() == "(") {
            throw incorrect_expression("Mismatched parentheses");
        }
        postfix.push_back(stack.top());
        stack.pop();
    }

    return postfix;
}

bool
InfixToPostfixConverter::hasHigherPrecedence(const std::string &op1, const std::string &op2,
                                             const OperationSet &opSet) {
    const Operation *operation1 = opSet.getOperation(op1[0]);
    const Operation *operation2 = opSet.getOperation(op2[0]);

    if (!operation1 || !operation2) {
        throw incorrect_expression("Unknown operation");
    }

    if (operation1->priority == operation2->priority) {
        return operation1->associativity == 'L';
    }

    return operation1->priority > operation2->priority;
}

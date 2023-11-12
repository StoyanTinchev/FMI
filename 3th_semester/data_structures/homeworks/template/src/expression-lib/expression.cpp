#include "expression.h"
#include "infix_to_postfix_converter.h"

void OperationSet::addOperation(const Operation &op) {
    operations.push_back(op);
}

const Operation *OperationSet::getOperation(char symbol) const {
    for (const auto &op: operations) {
        if (op.symbol == symbol) {
            return &op;
        }
    }
    return nullptr; // Operation not found
}

void initializeOperationSet(OperationSet &opSet, std::istream &ops) {
    std::string line;
    while (std::getline(ops, line)) {
        std::istringstream lineStream(line);
        Operation op = {};
        lineStream >> op.symbol >> op.operation >> op.priority >> op.associativity;
        opSet.addOperation(op);
    }
}

std::vector<std::string> tokenize(const std::string &str) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

double performOperation(double operand1, double operand2, char operation) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) throw incorrect_expression("Division by zero");
            return operand1 / operand2;
        default:
            throw incorrect_expression("Unknown operation");
    }
}

double evaluatePostfix(const std::vector<std::string> &postfix, const OperationSet &opSet) {
    std::stack<double> stack;

    for (const auto &token: postfix) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            stack.push(std::stod(token));
        } else {
            if (stack.size() < 2) throw incorrect_expression("Insufficient operands");
            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();

            const Operation *op = opSet.getOperation(token[0]);
            if (!op) throw incorrect_expression("Unknown operation");

            double result = performOperation(operand1, operand2, op->operation);
            stack.push(result);
        }
    }

    if (stack.size() != 1) throw incorrect_expression("Incorrect expression");
    return stack.top();
}

///
/// @brief Evaluates an expression.
///
/// @param expression
///   A null-terminated string that contains the expression.
/// @param ops
///   An input stream which contains the descriptions of all operations used in the expression.
///
/// @return The calculated value of the expression
///
double evaluate(const char *expression, std::istream &ops) {
    if (expression == nullptr) {
        throw incorrect_expression("Expression is null");
    }

    std::string exprStr = expression;
    if (exprStr.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
        return 0.0;
    }

    OperationSet opSet;
    initializeOperationSet(opSet, ops);

    std::vector<std::string> tokens = tokenize(expression);
    std::vector<std::string> postfix = InfixToPostfixConverter::convert(tokens, opSet);

    return evaluatePostfix(postfix, opSet);
}

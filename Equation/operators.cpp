#include "operators.h"
#include "utils.h"
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

double applyOperator(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default: return 0;
    }
}

double Evaluate(const string& expression) {
    stack<double> values;
    stack<char> ops;

    stringstream ss(expression);
    char token;
    bool expectOperand = true; // Flag to expect an operand after '(' or unary '-'
    bool lastTokenWasOperator = true; // Initially true to handle negative numbers
    while (ss >> token) {
        if (isdigit(token) || token == '.') {
            ss.putback(token);
            double num;
            ss >> num;
            values.push(num);
            expectOperand = false; // After pushing a number, an operator is expected next
            lastTokenWasOperator = false;
        }
        else if (token == '(') {
            ops.push('(');
            expectOperand = true; // After '(' or unary '-', an operand is expected next
            lastTokenWasOperator = true;
        }
        else if (token == ')') {
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();
                if (values.size() < 2) {
                    throw runtime_error("Invalid expression: Not enough operands for operator.");
                }
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOperator(a, b, op));
            }
            if (ops.empty()) {
                throw runtime_error("Invalid expression: Mismatched parentheses.");
            }
            ops.pop(); // Remove '(' from stack
            expectOperand = false; // After closing ')', an operator is expected next
            lastTokenWasOperator = false;
        }
        else if (isOperator(token)) {
            if (expectOperand && (token == '+' || token == '-')) {
                // Handle unary '+' and '-'
                if (token == '-' && lastTokenWasOperator) {
                    token = '_'; // Use '_' to denote unary '-'
                }
                else {
                    throw runtime_error("Invalid expression: Unexpected operator.");
                }
            }
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                char op = ops.top();
                ops.pop();
                if (values.size() < 2) {
                    throw runtime_error("Invalid expression: Not enough operands for operator.");
                }
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.push(token);
            expectOperand = true; // After an operator, an operand is expected next
            lastTokenWasOperator = true;
        }
        else {
            throw runtime_error("Invalid character in expression.");
        }
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        if (values.size() < 2) {
            throw runtime_error("Invalid expression: Not enough operands for operator.");
        }
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        values.push(applyOperator(a, b, op));
    }

    if (values.size() != 1) {
        throw runtime_error("Invalid expression: More than one value left in the stack.");
    }

    return values.top();
}
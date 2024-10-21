#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm> // Add this line

using namespace std;

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

bool isValidNumber(const string& token) {
    return std::all_of(token.begin(), token.end(), [](char c) { return isdigit(c); });
}

int evaluatePostfixExpression(const string& expression, bool &isValid) {
    stack<int> s;
    stringstream ss(expression);
    string token;
    while (ss >> token) {
        if (isValidNumber(token)) {
            s.push(stoi(token));
        } else if (isOperator(token)) {
            if (s.size() < 2) {
                isValid = false;
                return 0;
            }
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            if (token == "+") {
                s.push(operand1 + operand2);
            } else if (token == "-") {
                s.push(operand1 - operand2);
            } else if (token == "*") {
                s.push(operand1 * operand2);
            } else if (token == "/") {
                if (operand2 == 0) {  // Handle division by zero
                    isValid = false;
                    return 0;
                }
                s.push(operand1 / operand2);
            } else if (token == "^") {
                s.push(pow(operand1, operand2));
            }
        } else {
            isValid = false;
            return 0;
        }
    }

    if (s.size() != 1) {
        isValid = false;
        return 0;
    }

    isValid = true;
    return s.top();
}

int main() {
    string expression;
    getline(cin, expression);

    bool isValid;
    int result = evaluatePostfixExpression(expression, isValid);

    if (isValid) {
        cout << result << endl;
    } else {
        cout << "INPUT EXPRESSION IS INVALID" << endl;
    }

    return 0;
}

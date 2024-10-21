#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op){
    switch(op){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

bool isOperator(char c){
    return precedence(c)>0;
}

bool isHigherPrecedence(char op1, char op2){
    int precedence1= precedence(op1);
    int precedence2= precedence(op2);

    if(precedence1 == precedence2){
        if(op1=='^') return false;
        return true;
    }
    return precedence1 > precedence2;
}

bool isValid(const string& infix){
    int balance = 0;
    bool lastWasOperator = true;
    for(char c : infix){
        if(isalpha(c)){
            lastWasOperator = false;
        } else if(c == '('){
            balance++;
            lastWasOperator = true;
        } else if(c == ')'){
            balance--;
            if(balance<0) return false;
            lastWasOperator = false;
        }
        else if(isOperator(c)){
            if(lastWasOperator) return false;
            lastWasOperator = true;
        }
        else return false;
    }
    return balance == 0 && !lastWasOperator;
}

string convertToPostfix(const string& infix){
    if(!isValid(infix)) return "INPUT EXPRESSION IS INVALID";

    stack<char> opStack;
    string postfix;
    for(unsigned long int i=0; i<infix.length(); i++){
        char c;
        c = infix[i];
        if(isalpha(c)){
            postfix += c;
        } else if(c == '('){
            opStack.push(c);
        } else if(c == ')'){
            while(!opStack.empty() && opStack.top()!= '('){
                postfix += opStack.top();
                opStack.pop();
            }
            if(!opStack.empty()) opStack.pop();
        } else if (isOperator(c)){
            while(!opStack.empty() && isHigherPrecedence(opStack.top(), c)){
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while(!opStack.empty()){
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;    
}

int main() {
    string infix;
    cin >> infix;
    cout << convertToPostfix(infix) << endl;
    return 0;
}
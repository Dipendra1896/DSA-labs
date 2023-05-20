#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;
    
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            operators.push(ch);
        }
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
            else {
                // Mismatched parentheses error
                cout << "Error: Mismatched parentheses" << endl;
                return "";
            }
        }
        else if (isOperator(ch)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
        else {
            // Invalid character error
            cout << "Error: Invalid character" << endl;
            return "";
        }
    }
    
    while (!operators.empty()) {
        if (operators.top() == '(') {
            // Mismatched parentheses error
            cout << "Error: Mismatched parentheses" << endl;
            return "";
        }
        postfix += operators.top();
        operators.pop();
    }
    
    return postfix;
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    
    string postfix = infixToPostfix(infix);
    if (!postfix.empty()) {
        cout << "Postfix expression: " << postfix << endl;
    }
    
    return 0;
}


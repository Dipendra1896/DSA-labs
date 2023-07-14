#include <iostream>
#include <cstring>
using namespace std;

class Stack {
public:
    char *str;
    int size;
    int top;

public:
    Stack(int size) {
        this->size = size;
        str = new char[size];
        top = -1;
    }

    ~Stack() {
        delete[] str;
    }

    void push(char s) {
        if (top == size - 1) {
            cout << "\nSTACK OVERFLOW";
        } else {
            top = top + 1;
            str[top] = s;
        }
    }

    char pop() {
        if (top == -1) {
            cout << endl << "Stack is empty";
            return 0;
        } else {
            char i = str[top];
            top = top - 1;
            return i;
        }
    }
};

int precedence(char c) {
    if (c == '/' || c == '*') return 3;
    else if (c == '+' || c == '-') return 2;
    else return 1;
}

void infixToPostfix(char in[]) {
    int length = strlen(in);
    static int i = 0, px = 0;
    char s, t;
    char postfix[80];
    length = strlen(in);
    Stack st(length);

    while (i < length) {
        s = in[i];
        switch (s) {
            case '(': st.push(s); break;
            case ')': t = st.pop();
                      while (t != '(') {
                          postfix[px] = t; 
                          px = px + 1;
                          t = st.pop();
                      }
                      break;
            case '+': case '-': case '*': case '/':
                      while (st.top >= 0 && precedence(st.str[st.top]) >= precedence(s)) {
                          t = st.pop();
                          postfix[px] = t;
                          px++;
                      }
                      st.push(s);
                      break;
            default: postfix[px++] = s; break;
        }
        i = i + 1;
    }

    while (st.top >= 0) {
        t = st.pop();
        postfix[px++] = t;
    }
    postfix[px++] = '\0';
    cout << postfix << endl;
}

int main() {
    char infix[50];
    cout << "Enter the infix expression: ";
    cin.getline(infix, 50);
    infixToPostfix(infix);
    return 0;
}

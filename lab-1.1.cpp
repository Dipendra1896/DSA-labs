#include<iostream>
#include<string.h>
using namespace std;

// class to represent a stack of characters
class Stack {
public:
    char *str; // pointer to the array that stores the stack elements
    int size; // the capacity of the stack
    int top; // the index of the top element

public:
    // constructor to initialize the stack with a given size
    Stack(int size) {
        this->size = size;
        str = new char[size]; // allocate memory for the array
        top = -1; // set top to -1 to indicate an empty stack
    }

    // destructor to free the memory of the array
    ~Stack() {
        delete[] str;
    }

    // method to push a character into the stack
    void push(char s) {
        if (top == size - 1) {
            cout << "\nSTACK OVERFLOW: ";
        }
        else {
            top = top + 1;
            str[top] = s;
        }
    }

    // method to pop a character from the stack
    char pop() {
        char i;
        if (top == -1) {
            cout << endl << "Stack is empty";
            return 0;
        }
        else {
            i = str[top];
            top = top - 1;
        }
        return i;
    }
};

// method to determine operator precedence
int precedence(char c) {
    if (c == '/' || c == '*') return 3; // return 3 for * and /
    if (c == '+' || c == '-') return 2; // return 2 for + and -
    return 1; // return 1 for other operators, if any
}

// method to convert the infix to postfix
void infixToPostfix(char in[]) {
    int length;
    static int i = 0, px = 0;
    char s, t;
    char postfix[80];
    length = strlen(in); // find the length of the infix expression
    Stack st(length); // create a stack object with the same size as the infix expression

    while (i < length) {
        s = in[i]; // extract one by one character from infix
        switch (s) {
            case '(': st.push(s); break;
            case ')': t = st.pop(); // pop from the stack when a closing parenthesis is found
                      while (t != '(') {
                          postfix[px] = t; 
                          px = px + 1;
                          t = st.pop();
                      }
                      break;
            case '+': case '-': case '*': case '/':
                      while (precedence(st.str[st.top]) >= precedence(s)) {
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

    while (st.top > -1) {
        t = st.pop();
        postfix[px++] = t;
    }
    postfix[px++] = '\0';
    puts(postfix);
}

// driver program
int main(void) {
    char infix[50];
    cout << endl << "Enter the infix expression: "; // read the infix expression
    cin.getline(infix, 50);
    infixToPostfix(infix); // call the method
    return 0;
}
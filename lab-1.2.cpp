#include<iostream>
#include<string.h>
using namespace std;

class Stack {
private:
    int* s;
    int size;
    int top;

public:
    Stack(int size) {
        this->size = size;
        s = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] s;
    }

    void push(int no) {
        if (top == size - 1) {
            cout << "\nSTACK OVERFLOW: ";
        }
        else {
            top = top + 1;
            s[top] = no;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "\nSTACK UNDERFLOW";
        }
        else {
            cout << s[top] << " IS DELETED: ";
            --top;
        }
    }

    void traverse() {
        int i;
        if (top == -1) {
            cout << "\nSTACK IS EMPTY";
        }
        else {
            for (i = top; i >= 0; i--) {
                cout << s[i] << " ";
            }
        }
    }
};

int main() {
    int opt;
    int size;
    cout << "\nEnter the size of the stack: ";
    cin >> size;
    Stack s(size);

    while (1) {
        cout << "\nEnter the choice";
        cout << "\n1. PUSH 2. POP 3. DISPLAY 0. EXIT ";
        cin >> opt;

        if (opt == 1) {
            cout << "\nEnter the number to insert: ";
            cin >> opt;
            s.push(opt);
        }
        else if (opt == 2) {
            s.pop();
        }
        else if (opt == 3) {
            s.traverse();
        }
        else if (opt == 0) {
            exit(0);
        }
        else {
            cout << "\nINVALID CHOICE";
        }
    }

    return 0;
}

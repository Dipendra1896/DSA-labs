#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class Linked_List {
    struct node* head;
public:
    Linked_List() {
        head = NULL;
    }

    void InsertAtBeginning(int data) {
        struct node* NewNode;
        NewNode = new node;  // Use 'new' instead of 'malloc' in C++
        NewNode->data = data;
        if (head == NULL) {  // Use '==' instead of '=' for comparison
            NewNode->next = NULL;
            head = NewNode;
        }
        else {
            NewNode->next = head;
            head = NewNode;
        }

        cout << "One node is inserted." << endl;
    }
};

int main() {
    int data;
    cout << "Enter number to be inserted:" << endl;
    cin >> data;
    Linked_List obj;
    obj.InsertAtBeginning(data);  // Pass the 'data' variable, not 'int'
    return 0;  // Add return statement to main()
}


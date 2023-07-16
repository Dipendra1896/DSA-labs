#include<iostream>
using namespace std;
#define size 5
int stackArray[size];
int top = -1;

int isFull(){
    if(top == size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(isFull()){
        cout<<"stack Overflow!!"<<endl;
        return;
    }
    else{
    top = top+1;
    cout<<"Enter data to be inserted in the Stack:"<<endl;
    cin>>data;
    stackArray[top] = data;
    cout<<data<<" inserted Successfully."<<endl;
    }
    
}
int pop(){ 
    int value;
    if(isEmpty()){
        cout<<"stack is empty!!."<<endl;
        exit(1);
    }
    else{
    value = stackArray[top];
    top = top-1;
    cout<<value<<" Successfully deleted."<<endl;
    return value;
    }

}
int peek(){
    if(isEmpty()){
        cout<<"Stack is Empty!!"<<endl;
        exit(1);

    }
    cout<<"The top most element is:"<<stackArray[top]<<endl;
    return stackArray[top];
}
void display(){
    if(isEmpty()){
        cout<<"Stack Underfow!!"<<endl; 
        return;
    }
     cout<<"The Elements in the Stack are:"<<endl;
    for(int i=top;i>=0;i--)
     cout<<stackArray[i]<<endl;  

}
int main(){
    int choice,data;
    while(1){
        cout<<"\nSelect one of the Following choice:"<<endl;
        cout<<"1) PUSH AN ELEMENT IN THE STACK"<<endl;
        cout<<"2) POP AN ELEMENT FROM THE STACK"<<endl;
        cout<<"3) PRINT THE TOP MOST ELEMENT"<<endl;
        cout<<"4) PRINT ALL ELEMENTS IN THE STACK"<<endl;
        cout<<"5) EXIT"<<endl;
        cout<<" Enter your Choice(1/2/3/4/5):";
        cin>>choice;
        switch(choice){
            case 1:
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;    
            case 5:
                cout<<"Exited Successfully."<<endl;
                exit(0);
                break;
            default:
                cout<<"choose a valid number!!"<<endl;
                break;
                }
    }
    return 0;
}
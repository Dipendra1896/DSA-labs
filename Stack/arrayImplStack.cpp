#include<iostream>
using namespace std;
#define size 5
int stackArray[size];
int top = -1;

void push(int data){
    if(top == size-1){
        cout<<"stack Overflow!!"<<endl;
        return ;
    }
    top = top+1;
    cout<<"Enter data to be inserted in the Stack:"<<endl;
    cin>>data;
    stackArray[top] = data;
    cout<<data<<" inserted Successfully."<<endl;
    
}
int pop(){ 
    int value;
    if(top ==-1){
        cout<<"stack is empty!!."<<endl;
        exit(1); 
    }
    value = stackArray[top];
    top = top-1;
    cout<<value<<" Successfully deleted."<<endl;
    return value;

}
void display(){
    if(top == -1){
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
        cout<<"1) PUSH"<<endl;
        cout<<"2) POP"<<endl;
        cout<<"3) DISPLAY"<<endl;
        cout<<"4) EXIT"<<endl;
        cout<<"Choose one(1/2/3/4):"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            push(data);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
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
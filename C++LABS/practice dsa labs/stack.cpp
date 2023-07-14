#include<iostream>
using namespace std;
const int MAX=50;
class Stack{
    int top;
    int size[MAX];
    public:
    Stack (){
        top=-1;//initilize stack as empty
    }
    bool isFull()//checks whether the stack is full or not
    {
        if(top==MAX-1){
            return true;//returns true if stack is full
        }
            return false;//returns if the stack is not full
        }
    
    
    bool isEmpty() {            //checks whether the stack is empty or not
        if (top == -1){
            return true;// Returns true if the stack is empty
        }
        return false; //returns false if the stack is empty
    }

    void push(int newData)  //push data into the stack(check isFull condition in case of pushing data)
    {
         if(isFull())
    {
        cout<<"stack overflow."<<endl;//if stack is full then prints stack is overflow. if not then asks user for data to being pushed
       
    }
    else{
         cout<<"enter data to be inserted in the stack:"<<endl;
         cin>>newData;
         top++;
        size[top]=newData;
        cout<<newData<<" is Pushed into stack."<<endl;
       
    }  
  }
  void pop(int& poppedData){   //the parameter "poppedData" as a reference to store the popped value  this allows the function to modify the variable passed as an argument and return the popped value to the caller.
    if(isEmpty()){                //if stack is empty then prints stack underflow!data can not be popped
        cout<<"Stack underflow! data can not be popped."<<endl;
    }
    else{            //inside the else block "poppedData" is assigned the value of 'size[top]' bofore decrement of 'top'
        poppedData=size[top];
        top--;
        cout<<poppedData<<" is popped from the stack."<<endl;

    }

  }
  void display(){       //display the pushed data into the stack
    if(isEmpty()){
        cout<<"Stack is empty.";
    }
    else{
        cout<<"The stack elements are:\n";
        for(int i=top;i>=0;i--){
            cout<<size[i]<<"\n";

        }
        cout<<endl;
    }

  }  
    
};
int main(){
     int newData,poppedData;
       Stack obj;
    int choice=0;
    while(choice!=5){
        cout<<"\n Main Menu:"<<endl;
        cout<<"Choose one option from below:"<<endl;
        cout<<"\n1.push \n2.pop\n3.display\n4.exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                obj.push(newData);
                break;}
            case 2:{
                obj.pop(poppedData);
                break;}
            case 3:{    
                obj.display();
                break;}
            case 4:{
                    exit(0);
                }
            default:{
                cout<<" plz Enter valid choice.!!!"<<endl;  }  
        }
    };
    
}
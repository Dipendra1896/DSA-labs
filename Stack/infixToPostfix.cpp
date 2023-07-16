#include<iostream>
#include<string.h>
using namespace std;
#define size 100
char stack[size];
char infix[size],postfix[size];
int top=-1;

void push(char); 
char pop();
int isEmpty();
void inToPostfix();
int space(char);  
void display();
int precedence(char); 
int main(){
    cout<<"Enter the infix expression:"<<endl;
    cin>>infix;  

    inToPostfix();
    display();
    return 0;
   
} 
void inToPostfix(){
    int i,j=0;
    char symbol,next;
    for(i=0; i<strlen(infix); i++){
        symbol = infix[i];

        //if symbol is not a whitespace
        if(!space(symbol))
        {
            switch(symbol)
             {
                case '(':
                    push(symbol);
                    break; 
                case ')':
                    while((next=pop())!='(')
                    postfix[j++]=next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)){
                    postfix[j++] = pop();}
                    push(symbol);
                    break;
                default: //if the symbol is an oprand
                    postfix[j++] = symbol;    
            }         
        }
    }
    while(!isEmpty())
        postfix[j++] = pop(); 
        postfix[j] ='\0'; 
    
}
//defining the functions
int space(char c){
    //if symbol is a blank or a tab
    if(c == ' '|| c  =='\t'){
        return 1;
    }
    else{
        return 0;
    }
} 

int precedence(char symbol){
    switch(symbol){
        //Higher value means greater precedence
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default: 
            return 0;     

    }
}

void display(){
    int i=0;
    cout<<"The equivalent postfix expression is:"<<endl;
    while(postfix[i]){
        cout<<postfix[i++];
    }
    cout<<endl;
}
void push(char c){
    if(top ==size-1){
        cout<<"Stack Overflow!!"<<endl;
        return;
    }
    else{
        top= top+1;
        stack[top]=c;
    }
    }
 char pop(){
    char c;
    if(top == -1){
        cout<<"Stack Underflow!!"<<endl;
        exit(1);
    }
    else{
        c = stack[top];
        top = top-1;
        return c;
    }
}
int isEmpty(){
    if(top ==-1){
        return 1;
    }
    else{
        return 0;
    }
}

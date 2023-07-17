#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define size 50


int stack[size];
char infix[size],postfix[size];
int top =-1;
 
void push(int); 
int pop();
int isEmpty();
void inToPostfix();
int space(char);  
void display();
int precedence(char); 
int postEval();

int main(){
    int result;
    cout<<"Enter the infix expression:";
    cin>>infix;
    inToPostfix();
    result = postEval();
    display();
    cout<<"The result ontained after postfix evaluation is:"<<result<<endl;
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
void push(int value){
    if(top ==size-1){
        cout<<"Stack Overflow!!"<<endl;
        return;
    }
    else{
        top= top+1;
        stack[top]=value;
    }
    }
 int pop(){
    char value;
    if(top == -1){
        cout<<"Stack Underflow!!"<<endl;
        exit(1);
    }
    else{
        value = stack[top];
        top = top-1;
        return value;
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


int postEval(){
    int i ,a,b;
    for(i=0; i<strlen(postfix); i++){
        //if symbol is an oprand
        if(postfix[i]>='0' && postfix[i] <='9'){
            push(postfix[i] - '0');
        }
        else{
            a = pop(); 
            b = pop();

            switch(postfix[i]){
            case '+':
                push(b+a);
                break;   
            case '-':
                push(b-a);
                break;         
            case '*':
                push(b*a);
                break;
            case '/':
                push(b/a);
                break;
            case '^':
                push(pow(b,a));
                break;            

            }
        }
    }
    return pop();
}



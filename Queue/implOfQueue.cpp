#include<iostream>
using namespace std;
#define size 5
int queue[size];
int front=-1;
int rear=-1;
class QueueImpl{
    int data;
    public:
    void enqueue(){
        if(rear == size-1){
            cout<<"Queue Overflow!!"<<endl;
            return;
        }
        else if(front ==-1 && rear ==-1){
            cout<<"Enter the first data to be inserted in the Queue: ";
            cin>>data;
            front = 0;
            rear=rear+1;
            queue[rear]=data;
            cout<<data<<" enqueued successfully."<<endl;

        }
        else{
            cout<<"Enter the data to be enqueue: ";
            cin>>data;
            rear++;
            queue[rear]=data;
            cout<<queue[rear]<<" enqueued successfully."<<endl;
        }

    }

    void dequeue(){
        if(rear ==-1 && front ==-1){
            cout<<"Queue Underflow!!"<<endl;
            return;
        }
        else if(front ==rear){
            data = queue[front];
            front = rear =-1;
            cout<<data<<" successfully dequeued(now queue is empty)."<<endl;
        }
        else{
            data = queue[front];
            front++;
            cout<<data<<" successfully dequeue."<<endl;

        }
        
    }
    void display(){
        int i;
        if(front == -1 && rear == -1){
            cout<<"Queue is empty!!"<<endl;
        }
        else{
            cout<<"The element present in the queue:"<<endl;
            for(i=front;i<rear+1;i++){
            cout<<queue[i]<<endl;
            }
        }
    }
};
int main(){
    QueueImpl q;
    int choice,data;
    while(1){
        cout<<"Select one of the following choice: \n"<<endl;
        cout<<"1)Enqueue"<<endl;
        cout<<"2)Dequeue"<<endl;
        cout<<"3)display"<<endl;
        cout<<"4)Exit"<<endl;
        cout<<"Enter your choice(1/2/3/4):";
        cin>>choice;
        switch(choice){
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;     
            case 3:
                q.display();
                break;
            case 4:
                cout<<"Exited successfully."<<endl;
                exit(0);
                break;    
                    
            default:
                cout<<"Choose a valid choice!!"<<endl;
                break;    
                     
        }
    }
    return 0;
}
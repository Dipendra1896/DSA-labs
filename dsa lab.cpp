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
//insertion at beginning
    void InsertAtBeginning(int data) {
        struct node* NewNode;
        NewNode = new node();  // Use 'new' instead of 'malloc' in C++
        NewNode->data = data;
        if (head == NULL) {  
            NewNode->next = NULL;
            head = NewNode;
        }
        else {
            NewNode->next = head;
            head = NewNode;
        }

        cout << "One node is inserted." << endl;
    }
    //Insertion after a  specified node
    void InsertAfterNode(int searchData,int newData){
    	if(head==NULL){
    		cout<<"List is empty,data can not be inserted after a node!!!"<<endl;
    		return ;
		}
		struct node*previousNode=head;
		while(previousNode!=NULL){
			if(previousNode->data==searchData){
				struct node*NewNode;
				NewNode=new node();
				NewNode->data=newData;
				NewNode->next=previousNode->next;
				previousNode->next=NewNode;
				cout<<"One node is inserted after a  specified node."<<endl;
				return ;
			}
			previousNode=previousNode->next;
		}
		cout<<"Specified node is not Found!!!"<<endl;
	}
	//Insertion before a node
	 void InsertBeforeNode(int searchData1,int newData1){
    	if(head==NULL){
    		cout<<"List is empty,data can not be inserted before a node!!!"<<endl;
    		return ;
		}
		if (head->data == searchData1) {
			struct node* NewNode = new node();
            NewNode->data = newData1;
            NewNode->next = head;
            head = NewNode;
            cout << newData1<<" is inserted before the specified node." << endl;
            return;
            
        }
    
		struct node*currentNode;
		//for(currentNode=head;currentNode->next!=NULL&&currentNode->next->data!=searchData1;currentNode=currentNode->next);
			if(currentNode->next!=NULL){
				struct node*NewNode=new node();
				NewNode->data=newData1;
				NewNode->next=currentNode->next;
				currentNode->next=NewNode;
				cout<<newData1<<" is inserted before a  specified node."<<endl;
			}
			else{
				cout<<"Specified node is not Found!!!"<<endl;
		    }
	}

	//insertion at last
	void InsertAtLast(int data1){
		struct node*newNode;
		newNode=new node();
		newNode->data=data1;
		newNode->next=NULL;
		
		if(head==NULL){
			head=newNode;
		}
		else{
			struct node*currentNode=head;
			while(currentNode->next!=NULL){
				currentNode=currentNode->next;
			}
			 currentNode->next=newNode;
		}
		cout<<"One node is inserted at the end."<<endl;	
	}
};

int main() {
    int data,searchData ,newData,searchData1,newData1,data1,choice;
     Linked_List obj;
    cout << "Enter number to be inserted at beginning:" << endl;
    cin >> data;
    obj.InsertAtBeginning(data);  // Pass the 'data' variable, not 'int'
   cout<<"Enter the data of specified node after which new node is inserted:"<<endl;
   cin>>searchData;
   cout<<"Enter data value of the node being inserted after preceeding node:"<<endl;
   cin>>newData;
   obj.InsertAfterNode(searchData,newData);
   cout<<"Enter the data of specified node before which new node is inserted:"<<endl;
   cin>>searchData1;
   cout<<"Enter data value of new node being inserted before an existing node :"<<endl;
   cin>>newData1;
   obj.InsertBeforeNode(searchData,newData);
   cout << "Enter number to be inserted at the end:" << endl;
   cin>>data1;
   obj.InsertAtLast(data1);
//    while(1){
//    	cout<<"Enter your choice:"<<endl;
//    	cout<<"\n1. forInsertingAtBeginning 2.forInsertingAfterNode 3.forInsertingBeforeNode 4.forInsertingAtLast 0.forExiting"<<endl;
//    	cin>>choice;
//    	if(choice==1){
//    		obj.InsertAtBeginning(data);
//		}
//		else if(choice==2){
//			obj.InsertAfterNode(searchData,newData);
//		}
//		else if(choice==3){
//			obj.InsertBeforeNode(searchData,newData);
//		}
//		else if(choice==4){
//		    obj.InsertAtLast(data1);
//		}
//		else if(choice==0){
//			exit(0);	
//		}
//		else{
//			cout<<"\nInvalid choice."<<endl;
//		}
//    	
//	}
	return 0;
}


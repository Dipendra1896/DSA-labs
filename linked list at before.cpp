#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*next;
};
class Insertion{
	struct node*head;
	public:
		Insertion(){
			head=NULL;
		}
		void insertBeforeNode(int searchData,int data){
			struct node*NewNode,*temp;
			NewNode=new node();
			if(NewNode==NULL){
				cout<<"overflow.";
			}
			else{
				cout<<"enter element value:";
				cin>>data;
				NewNode->data=data;
				cout<<"Enter location where node is inserted:"<<endl;
				cin>>searchData;
				temp=head;
				for(int i=0;i<searchData;i++){
					temp=temp->next;
					if(temp==NULL){
						cout<<"Node can not inserted."<<endl;
						return;
					}
				}
				NewNode->next=temp->next;
				temp->next=NewNode;
				cout<<"Node is inserted before an existing node."<<endl;
			}
			
		}
	
};
int main(){
	int searchData,data;
	Insertion obj;
	obj.insertBeforeNode(searchData,data);
}

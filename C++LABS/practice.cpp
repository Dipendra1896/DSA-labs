#include<iostream>
using namespace std;
class person
{
	int age,citizenship_number;
	char name[20],address[30];
	public:
		void getdata()
		{
			cout<<"enter name,age and address:"<<endl;
			cin>>name>>age>>address;
			if(age>=16){
				cout<<"enter citizenship number:"<<endl;
				cin>>citizenship_number;
			}
			else{
				citizenship_number=0;
				cout<<"citizenship number:"<<citizenship_number<<endl;
			}
		}
		void display(){
			cout<<"the name,age,address and citizenship number are:"<<endl;
			cout<<name<<endl;
			cout<<age<<endl;
			cout<<address<<endl;
			cout<<citizenship_number<<endl; 
		}
};
int main()
{
	person ob;
	ob.getdata();
	ob.display();
	
}

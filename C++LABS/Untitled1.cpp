#include<iostream>
using namespace std;
class Person
{
	int age,citizenship_number;
	char name[20],address[30];
	public:
		void getdata()
		{
			cout<<"Enter name,age and address of a person:"<<endl;
			cin>>name>>age>>address;
			if(age>16)
			{
				cout<<"Enter your citizenship number:"<<endl;
				cin>>citizenship_number;
			}
			else{
				citizenship number is = 0;
			}
		}
		void displaydata()
		{
			cout<<"The name,age,address and citizenship number are:"<<endl;
			cout<<name<<endl;
			cout<<age<<endl;
			cout<<address<<endl;
			cout<<citizenship_number<<endl;
		}
};
 main()
{
	Person st;
	st.getdata();
	st.displaydata();
}

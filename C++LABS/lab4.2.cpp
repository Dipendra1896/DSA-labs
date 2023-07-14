#include<iostream>
using namespace std;
class GCES;
class PEC
{
	int st_num1;
	public:
		getdata1()
		{
			cout<<"Enter the numbers of students in pokhara engineering campus:"<<endl;
			cin>>st_num1;
		}
		friend void compare(PEC,GCES);
};
class GCES
{
	int st_num2;
	public:
	    void getdata2()
	    {
		    cout<<"Enter the numbers of students in gandaki college of engineering and science:"<<endl;
		    cin>>st_num2;
     	}
	    friend void compare(PEC,GCES);
};
 void compare(PEC p,GCES g)
 {
 	if(p.st_num1>g.st_num2)
 	{
 		cout<<"PEC has greater no. of students & the no.is:"<<p.st_num1<<endl;
	 }
	 else if(p.st_num1==g.st_num2)
	 {
	 	cout<<"PEC and GCES have equal no. of students."<<endl;
	 }
	 else
	 {
	 	cout<<"GCES has greater no of students & the no.is:"<<g.st_num2<<endl;
	 }
	 
 };
 
 int main()
 {
 	PEC ob1;
 	GCES ob2;
 	ob1.getdata1();
 	ob2.getdata2();
	compare(ob1,ob2); 
 }

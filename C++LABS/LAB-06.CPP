#include<iostream>
using namespace std;
class Class1
{
  protected:
    int num1;
     public:
         Class1()
            {
  	            cout<<"Enter the first number:"<<endl;
  	            cin>>num1;
            }
};
class Class2
{
  protected:
	 int num2;
	 public:
	 	Class2()
	 	{
	 		cout<<"Enter the second number:"<<endl;
	 		cin>>num2;
		 }
};
class Class3:public Class1,public Class2
{
	public:
		Class3()
		{
    	cout<<"The sum of two numbers="<<num1+num2<<endl;
        } 
};
main()
{
    Class3 ob;
    
}

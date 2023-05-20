#include<iostream>
using namespace std;
class Compare
{
	int n1,n2;
	public:
		getvalue()
		
		{
			cout<<"Enter two numbers:"<<endl;
			cin>>n1>>n2;
		}
		friend void compare(Compare);
};
void compare(Compare c)
{
	if(c.n1>c.n2)
	{
		cout<<"n1 is greatest."<<endl;
	}
	else if(c.n1==c.n2)
	{
		cout<<"Both are equal."<<endl;
	}
	else
	{
		cout<<"n2 is greatest."<<endl;
	}
};
int main()
{
	Compare ob;
	ob.getvalue();
	compare(ob); 
}

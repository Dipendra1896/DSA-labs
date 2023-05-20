#include<iostream>
using namespace std;
class Time
{
	int hr,min,sec;
	public:
		int total_sec;
		 void getdata()
		{
			cout<<"Enter time in hours,minutes & seconds:"<<endl;
			cin>>hr>>min>>sec;
			total_sec=(hr*3600)+(min*60)+sec;
		}
		friend Time output(Time,Time);
};
Time output(Time t1,Time t2)
{
	Time t4;
	int sum;
	sum=t1.total_sec+t2.total_sec;
	t4.hr=sum/3600;
	t4.min=sum/60;
	t4.sec=sum;
	cout<<t4.hr<<":"<<t4.min<<":"<<t4.sec<<endl;
	return t4;
}
int main()
{
	Time t,t3,t5;;
	t.getdata();
	t3.getdata();
	cout<<"sum of time of two objects is:"<<endl;
	t5=output(t,t3);
}


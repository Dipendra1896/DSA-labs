#include<iostream>
using namespace std;
class Rectangle{
    public:
    int l,b,A;
    void getdata(){
        cout<<"enter length and breadth:"<<endl;
        cin>>l>>b;
    }
    void area(){
        A=l*b;
        cout<<"Area is:"<<A<<endl;
    }
};
  main(){
    Rectangle obj;
    obj.getdata();
    obj.area();
 };
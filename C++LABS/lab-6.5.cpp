#include<iostream>
#include<string.h>
using namespace std;
class Shape
{
  protected:
    float length,breadth;
};
class Triangle : public Shape
{
  public:
    Triangle(){
      cout<<"enter the length and breadth of triangle:-"<<endl;
      cin>>length>>breadth;
      cout<<"Area of triangle is:- "<<length*breadth/2<<endl;
    }
  };
class Rectangle : public Shape{
  public:
    Rectangle(){
      cout<<"enter the length and breadth of rectangle:-"<<endl;
      cin>>length>>breadth;
      cout<<"Area of rectangle is:- "<<length*breadth<<endl;
    }
};
main(){
  Triangle t;
  Rectangle r;
}


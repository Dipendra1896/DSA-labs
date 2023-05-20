#include<iostream>
#include<string.h>
using namespace std;
class Vehicle
{
  protected:
    float length,breadth;
  public:
     virtual void display()=0;//pure virtual function
     void show(){
        cout<<"Vehicle includes- Car and Bus:"<<endl;
     }
};
class Car : public Vehicle
{
  public:
    void display(){//function overriding
      cout<<"Car--Mercedes & Tesla."<<endl;
    }
  };
class Bus : public Vehicle{
  public:
     void display(){//function overriding
      cout<<"Bus--Single deeker & Double deeker."<<endl;
    }
};
main(){
    // Vehicle v;
    Car c;
    Bus b;
    c.show();
    c.display();
    b.display();
}


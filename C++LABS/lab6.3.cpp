#include<iostream>
using namespace std;
class Student
{
  protected:
    int roll_no;
  public:
    Student(){
        cout<<"enter the  roll number:"<<endl;
        cin>>roll_no;
    }
};
class Test : public Student
{
  protected:
    int m1,m2;
  public:
    Test(){
        cout<<"enter the  mark1 and mark2 resp. :"<<endl;
        cin>>m1>>m2;
    }
};
class Result : public Test{
    protected:
        int tot;
    public:
        Result(){
            tot=m1+m2;
            cout<<"ROll no="<<roll_no<<endl;
            cout<<"Total marks="<<tot<<endl;
        }
};
main(){
    Result ob;
}


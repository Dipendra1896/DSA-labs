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
    void display(){
        cout<<"roll no="<<roll_no<<endl;
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
    void display_data(){
        cout<<"mark in 2 sub are::"<<m1<<" & "<<m2<<endl;
    }
};
class Sport
{
  protected:
    int score;
  public:
    Sport(){
        cout<<"enter the  score in sports :"<<endl;
        cin>>score;
    }
    void display_score(){
        cout<<"mark in sport::"<<score<<endl;
    }
};
class Result : public Test, public Sport{
    protected:
        int tot;
    public:
        Result(){
            tot=m1+m2;
            cout<<"Total marks="<<tot<<endl;
            cout<<"Sport-score="<<score<<endl;
        }
};
main(){
    Result ob;
    ob.display();
    ob.display_data();
    ob.display_score();
}


#include<iostream>
using namespace std;
int main(){
    int numArray[3];
   // numArray[10,20,30,40,50,60];
    numArray[0]=10;
    numArray[1]=20;
    numArray[2]=30;
    numArray[3]=40;
    numArray[4]=50;
    numArray[5]=60;
    for( int i=0;i<=5;i++){
        cout<<numArray[i]<<endl;
    }
    return 0;
}
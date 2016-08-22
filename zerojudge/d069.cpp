#include <iostream>

using namespace std;
int main()
{
    int in0 ,in1;
    
    cin >>in0 ;
    while (in0-- && cin >>in1){
          cout <<( ((in1%4==0&&in1%100!=0)||(in1%400==0)) ?"a leap year":"a normal year") <<endl ; ;
    }
}

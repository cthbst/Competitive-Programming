#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int in0 ;
    
    cin >>in0 ;
    
    for (int i=1 ;i<=in0;i++ ){
        int in1 ,in2 ;
          
          cin >>in1 >>in2 ;
          if (in1%2 ==0 ){
             in1 +=1 ;
          }
          if (in2%2 ==0 ){
             in2 -=1 ;
          }
          
          cout <<"Case "<<i <<": " <<(in2 +in1 )*((in2 -in1 )/2+1 ) /2 <<endl ;
    }
    
    return 0 ;
}

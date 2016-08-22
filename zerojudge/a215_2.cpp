#include <iostream>

using namespace std;

int main()
{
    int in0 ,in1 ;
    
    while (cin >>in0 >>in1 ){
          
          int out=0 ;
          
          for (int i=0 ;(i+in0)<=in1;i++){
              out++ ;
              in1-=(in0 +i ) ;
          }
          
          cout <<out+1 <<endl ;
          
    }
}

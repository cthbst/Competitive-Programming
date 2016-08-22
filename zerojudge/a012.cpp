#include <iostream>

using namespace std;

int main()
{   
    long long int  in0 ,in1 ;
    
    while (cin >>in0 >>in1 ){
          
          if (in0 >in1 )
             cout <<in0 -in1 ; 
          else 
               cout <<in1 -in0 ;
          
          cout <<endl ;
    }
    
}

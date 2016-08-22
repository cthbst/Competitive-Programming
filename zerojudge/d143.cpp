#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    long long int in0 ;
    
    cin >>in0 ;
    while (in0-- ){
          int in1 ,in2 ;
          
          cin >>in1 >>in2 ;
          
          if (in1 >in2 ){
             cout <<">" ;
          }
          else if (in1 <in2){
               cout <<"<" ;
          }
          else {
               cout <<"=" ;
          }
          cout <<endl ;
    }
    
    return 0;
}

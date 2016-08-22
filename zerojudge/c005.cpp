#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    long long int in0 ;
    
    cin >>in0 ;
    while (in0-- ){
          long long int in1 ,sum =0 ;
          
          cin >>in1 ;
          while (in1-- ){
                long long int in[3] ;
                
                cin >>in[0] >>in[1] >>in[2] ;
                sum +=in[0] *in[2] ;
          }
          cout <<sum <<endl ;
    }    
    return 0 ;
}

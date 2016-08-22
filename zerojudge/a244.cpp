#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int a ;
    cin >>a ;
    while (a-- ){
          long long int in1 ,in2 ,in3 ;
          cin >>in1 >>in2 >>in3 ;
          if (in1==1)
             cout <<in2 +in3 ;
          else if (in1==2 )
               cout <<in2 -in3 ; 
          else if (in1==3)
               cout <<in2 *in3 ;
          else 
               cout <<in2 /in3 ;
          cout <<endl ;
    }
    return EXIT_SUCCESS;
}

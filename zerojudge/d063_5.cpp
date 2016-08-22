#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int a;
    cin >>a ;
    while (a--){
          int in1 ,in2 ,in3 ;
          cin >>in1 >>in2 >>in3 ;
          if (in1!=in2 && in2!=in3 && in3!=in1){
             cout <<"YES" ;
          }
          else {
               cout <<"NO" ;
          }
          cout <<endl ;
    }
    
    return EXIT_SUCCESS;
}

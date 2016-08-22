#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int in1 ,in2 ;
    while (cin >>in1 >>in2 ){
          if (in1==0 && in2==0)
             return EXIT_SUCCESS;
          cout <<(in1 %2==in2 %2?"Win":"Loss")<<endl ;
    }
    
    return EXIT_SUCCESS;
}

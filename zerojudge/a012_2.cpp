#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[])
{
    long long int in1 ,in2 ;
    while (cin >>in1 >>in2){
          cout <<(in1>in2?in1-in2:in2-in1)<<endl;
    }
    return EXIT_SUCCESS;
}

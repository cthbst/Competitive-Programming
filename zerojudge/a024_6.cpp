#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int in0 ;
    cin >>in0 ;
    while (in0--){
          int in1 ,in2 ,in3 ,in4 ,out1=0,out2=0 ;
          cin >>in1 >>in2 >>in3 >>in4 ;
          int temp ;
          if (in2>in3){
             out1=(in1-in3*in4)/(in2-in3);
             out2=in4-out1;
          }
          else {
               out2=(in1-in2*in4)/(in3-in2);
               out1=in4-out2;
          }
          cout <<out1 <<" " <<out2 <<endl;
          }
    return EXIT_SUCCESS;
}

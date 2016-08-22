#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int in0 ,in1 ,in2 ;
    
    while (cin >>in0 >>in1 >>in2 ){
          int ru ;
          
          ru =(in0 +in1 +in2) /2 ;
          
          cout << ru *(ru-in0) *(ru-in1) *(ru-in2) <<endl ;
    }
    return 0;
}

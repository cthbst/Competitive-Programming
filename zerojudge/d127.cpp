#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    long long int in0 ;
    
    while (cin >>in0 ){
          cout <<(in0 %4 ==0 ?(in0 /4) *(in0 /4):(in0 /4) *(in0 /4+1)) <<endl ;
    }
    return 0;
}

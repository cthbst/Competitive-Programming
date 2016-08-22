#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int in0 ;
    
    while (cin >>in0 && in0 !=0 ){
          int out =0 ;
          
          for (int i=1 ;i<=in0 ;i++ ){
              out +=i*i ;
          }
          
          cout <<out <<endl ;
    }
    
    return 0;
}

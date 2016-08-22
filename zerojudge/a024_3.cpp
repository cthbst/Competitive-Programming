#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{   
    int input[2] ;
    while (cin >>input[0] >>input[1]){
          int out=1 ;
          for (int i=1 ;i<=input[0] && i<=input[1];i++){
              if (input[0]%i==0 && input[1]%i==0 ){
                 out=i ;
              }
          }
          cout <<out <<endl ;
    }
}

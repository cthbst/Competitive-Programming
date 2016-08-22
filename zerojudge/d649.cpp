#include <iostream>

using namespace std;

int main()
{
    short in0 ;
    
    while (cin >>in0 ){
          for (short i=1 ;i<=in0;i++ ){
              for (int i1=0 ;i1<(in0-i);i1++ ){
                  cout <<"_" ;
              }
              for (int i1=0 ;i1<i;i1++ ){
                  cout <<"+" ;
              }
              cout <<endl ;
          }
          
    }
}

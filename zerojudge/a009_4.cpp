#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char in0[200] ;
    
    while (cin.getline(in0,200)){
          
          for (short i=0 ;i<strlen(in0);i++ ){
              in0[i]+='*'-'1' ;
          }
          
          cout <<in0 <<endl ;
    }
}

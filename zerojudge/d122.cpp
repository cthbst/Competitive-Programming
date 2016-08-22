#include <iostream>

using namespace std;

int  pt(short in0){
    
    int out=1 ;
    
    for (short i=1 ;i<=in0 ;i++ ){
        out *=5 ;
    }
    
    return out ;
}

int main()
{
    int in0 ;
    
    
    
    while (cin >>in0 ){
          long long int out =0 ;
          
          for (long long int i=1 ;pt(i) <=in0 && i<14 ;i++ ){
              out +=in0/pt(i) ;
          }
    
          cout <<out <<endl ;
    }
    
}

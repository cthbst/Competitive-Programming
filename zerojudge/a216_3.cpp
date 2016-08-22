#include <iostream>

using namespace std;

long long int f (int n ){
          
     return n + n*(n-1) /2 ;
}

long long int g (int n ){
     
     if (n==1 ){
        return 1; 
     }
     
     return f(n) + g(n-1) ;
}

int main()
{
    long long int in0 ;
    
    while (cin >>in0 ){
          cout <<f(in0) <<" " <<g(in0) <<endl ;
    }
}

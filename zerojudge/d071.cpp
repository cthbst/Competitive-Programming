#include <iostream>

short pd (int in0 ){
      if (in0 %400 ==0 ){
         return 1 ;
      }
      else if (in0 %100 ==0 ){
           return 0 ;
      }
      else if (in0 %4 ==0 ){
           return 1 ;
      }
      else {
           return 0 ;
      }
}

using namespace std;
int main(int argc, char *argv[])
{
    int in0 ;
    
    while (cin >>in0 && in0 != 'EOF' ){
          cout <<(pd(in0) ==0 ?"a normal year" :"a leap year" ) <<endl ;
    }
    
    return 0;
}

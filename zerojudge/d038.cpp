#include <iostream>
using namespace std;

int main () {
    int in0 ;
    
    while (cin >>in0 && in0 !=0 ){
          long long int ru1 =0,ru2 =1 ,out ;
          
          for (int i=0 ;i<in0 ;i++ ){
              out =ru1 +ru2 ;
              ru1 =ru2 ;
              ru2 =out ;
          }
          
          cout <<out <<endl ;
    }
    return 0 ;
}

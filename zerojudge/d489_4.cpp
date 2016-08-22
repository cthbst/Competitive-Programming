#include <iostream>
using namespace std;

int main () {
    int in0 ;
    
    while (cin >>in0 &&in0 !=0 ){
          int sum =0 ,ru ;
          
          while (in0-- ){
                cin >>ru ;
                sum += ru *ru ;
          }
          
          cout <<sum <<endl ;
    }
    return 0 ;
}

#include <iostream>

using namespace std;
int main()
{
    int in0 ,in1 ;
    
    while (cin >>in0 >>in1 ){
          if (in0 ==in1){
             cout <<"Ok!" <<endl ;
          }
          else {
               cout <<(in1 !=0 &&in0 %in1 ==0 ?"Ok!" :"Impossib1e!" ) <<endl ;
          }
    }
    return 0 ;
}

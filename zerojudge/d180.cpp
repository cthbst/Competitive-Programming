#include <iostream>

using namespace std;
int main()
{
    int in0 ,sum0 =0,sum1 =0,in1 ; 
    
    cin >>in0 ;
    while (in0--){
          cin >>in1 ;
          (in0 %2==0 ?sum0+=in1 :sum1+=in1 ) ;
    }
    cout <<(sum0 >sum1 ?"right" :"left" ) <<endl ;
    
    return 0 ;
}

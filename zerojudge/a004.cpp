#include <iostream>

int pd (int in0){
    
    if (in0 %400 ==0 )
       return 1 ;
    else if (in0 %100 ==0 )
         return 0 ;
    else if (in0 %4 ==0 )
         return 1 ;
    else 
         return 0 ;
}

using namespace std;

int main()
{
    int in0, out;
    
    while (cin >>in0 ){
          
          cout <<(pd(in0)==1 ?"閏年" :"平年" ) <<endl ;
    }

}

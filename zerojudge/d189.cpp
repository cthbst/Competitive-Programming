#include <iostream>

using namespace std;

int main()
{
   short in0 ;
   
   while (cin >>in0 ){
         short out=in0 ;
               
         while (in0 >=3){
               out +=in0/3 ;
               in0= in0/3 +in0%3 ;
         }
         
         if (in0 ==2 ){
            out++ ;
         }
         
         cout <<out <<endl ;
         
   }
}

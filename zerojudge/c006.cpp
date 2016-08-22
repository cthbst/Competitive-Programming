#include <iostream>

short pd0 (short from ,short to ,short a ){
      int out =from -to ;
      
      if (out <0 ){
         out +=40 ;
      }
      
      return (a==1 ?out :40 -out) *9 ;
}

using namespace std;
int main(int argc, char *argv[])
{
    short in[4] ;
    
    while (cin >>in[0] >>in[1] >>in[2] >>in[3] ){
          if (in[0] ==0 && in[1] ==0 && in[2] ==0 && in[3] ==0 ){
             return 0;
          }
          
          short out=1080 ;
          
          out +=pd0(in[0],in[1],1 );
          out +=pd0(in[1],in[2],0 );
          out +=pd0(in[2],in[3],1 );
          
          cout <<out <<endl ;
    }
 
    return 0 ;
}

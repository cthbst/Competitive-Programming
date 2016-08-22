#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int i=5 ,in[3] ,out=0 ;
    
    while (i-- ){
          int large =0;
          
          cin >>in[0] >>in[1] >>in[2] ;
          
          for (int i=0 ;i<2;i++ )
              if (in[i] >in[2] ){
                 int temp ;
                 
                 temp =in[i] ;
                 in[i] =in[2] ;
                 in[2] =temp ;
              }
          
          if (in[2] <in[0] +in[1] ){
             out++ ;
          }
    }
    cout <<out <<endl ;
    return 0;
}

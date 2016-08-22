#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    short in0 ;
    
    while (cin >>in0 && in0 !=0 ){
          int in[in0] ,sum =0 ,out =0 ;
          
          for (int i=0 ;i<in0;i++ ){
              cin >>in[i] ;
              sum +=in[i] ;
          }
          
          for (int i=0 ;i<in0;i++ )
              if (in[i]*in0 < sum ){
                 out++ ;
              }
          
          cout <<out <<endl ;
    }
    
    return 0;
}

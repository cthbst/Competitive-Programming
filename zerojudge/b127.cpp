#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int in0 ;
    
    while (cin >>in0 ){
          int ru0 =0 ,ru1 =1 ,out =0 ;
          
          for (int i=0 ;i<in0;i++ ){
              out =ru0 +ru1 ;
              ru0 =ru1 ;
              ru1 =out ;
          }
          cout <<out <<endl ;
    }
    return 0;
}

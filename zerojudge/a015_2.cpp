#include <iostream>

using namespace std;

int main()
{
    int in0 ,in1 ;
    
    while (cin >>in0 >>in1 ){
          int squrt[in0][in1] ;
          
          for (int i =0 ;i<in0 ;i++)
              for (int i1 =0 ;i1<in1;i1++){
                  cin >>squrt[i][i1] ;
              }
          
          for (int i =0 ;i<in1 ;i++){
              for (int i1 =0 ;i1<in0;i1++){
                  cout <<squrt[i1][i] <<" ";
              }
              cout <<endl ;
          }
          
    }
    
}

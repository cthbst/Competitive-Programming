#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int in0;
    while (cin >>in0 ){
          int in[in0];
          for (int i=0;i<in0;i++)
              cin >>in[i] ;
              
          for (int i=0;i<in0;i++){
              for (int i1=0;i1<in0;i1++){
                  if (in[i]<in[i1]){
                     int a;
                     a=in[i];
                     in[i]=in[i1];
                     in[i1]=a;
                  }
              }
          }
          
          for (int i=0;i<in0;i++)
              cout <<in[i] <<" ";
              
          cout <<endl ;
    }
    
    return EXIT_SUCCESS;
}

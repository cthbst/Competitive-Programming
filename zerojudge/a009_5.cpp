#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    short in0 ;
    cin >>in0 ;
    
    
    while (in0-- ){
          char in1[101] ;
          short out =0 ;
          
          cin >>in1 ;
          
          for (short i=0 ;i<strlen(in1)/2+1;i++ ){
              if (in1[i]!=in1[strlen(in1)-1-i]){
                 out=1 ;
                 break ;
              }
          }
          
          cout <<(out==0 ?"yes":"no") <<endl ;
          
    }
}

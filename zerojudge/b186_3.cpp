#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    long int in[0] ;
    
    while (cin >>in[0] >>in[1] && (in[0]+in[1])){
          if (in[0]>in[1]){
             int c =in[1] ;
             in[1] =in[0] ;
             in[0] =c ;
          } 
          //小
          double d_k= sqrt(in[1]*in[1]-in[0]*in[0]) ;
          if (d_k-(int)d_k==0.0){
             cout <<d_k <<" ";
          }
          
          //大 
          double d_k2= sqrt(in[1]*in[1]+in[0]*in[0]) ;
          if (d_k2-(int)d_k2==0.0){
             cout <<d_k2 <<" ";
          }
          //wrong
          if (d_k2-(int)d_k2!=0.0 && d_k-(int)d_k!=0.0){
             cout <<"Wrong" ;
          }
          cout <<endl ;
    }
    return 0;
}

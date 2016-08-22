#include <iostream>
using namespace std;
int main(void){
    int in[7][2] ,pt[2]={0};
     
    for (short i=0 ;i<7 ;i++ ){
        for (short i1=0 ;i1<2 ;i1++ ){
            cin >>in[i][i1] ;
        }
        if (pt[1]<in[i][0]+in[i][1] && in[i][0]+in[i][1] >=8 ){
           pt[0]=i+1 ;
           pt[1]=in[i][0]+in[i][1] ;
        }
    }
    
    cout << pt[0] <<endl ;
     

    return 0;
}

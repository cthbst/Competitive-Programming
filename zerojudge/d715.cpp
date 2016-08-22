#include<stdio.h>

int p[]={6,6,2,6,4,4,4,8,4,6} ;
int t[]={6,2,4,8} ;

int main(){
    int N ;

    while (~scanf("%d",&N ) ){
        int Ans=1 ;
        long long int B=0 ;

        while (N>=5){
            Ans*=p[N%10] ;
            Ans%=10 ;
            N/=5 ;
            B+=N ;
        }
        Ans*=t[((-B)%4+4)%4]*(N==1?1:p[N]) ;
        Ans%=10 ;
        printf("%d\n",Ans) ;
    }
}

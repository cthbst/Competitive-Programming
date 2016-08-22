#include<stdio.h>

int main(){
    long long int  N ,d ,c;
    while (scanf("%lld",&N ) && N!=0 ){
        c=0 ,d=1 ;
        printf("The parity of ") ;
        while (d<<1<=N)d<<=1 ;
        while (d){
            printf("%d",(N&d)>0) ;
            c+=((N&d)>0) ;
            d>>=1 ;
        }
        printf(" is %lld (mod 2).\n",c) ;
    }
}

#include<stdio.h>

int main(){
    int T ; scanf("%d",&T ) ;

    long long x ;
    while (T-- && scanf("%I64d",&x )){
        long long i = ( x&(-x) )>>1 ;
        long long l=x ,r=x ;
        while (i>0)l-=i ,r+=i ,i>>=1 ;
        printf("%I64d %I64d\n",l ,r ) ;
    }
}

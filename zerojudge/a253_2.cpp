#include<stdio.h>
#include<string.h>

int main(){
    long long int a[130] ;
    memset(a,0,sizeof(a)) ;

    long long int S,N ;
    while (scanf("%lld",&S ) && S>=0 && scanf("%lld",&N) )a[S]=N ;
    while (scanf("%lld",&S ) && S>=0 && scanf("%lld",&N) )a[S]+=N ;
    for (int i=0 ;i<130 ;i++ )if (a[i]!=0){
        printf("%d %lld\n",i ,a[i]) ;
    }
}

#include<stdio.h>

typedef long long int LL ;

LL modual(LL N ,LL p){ // p^(N-1) % N =??
    if (N%p==0)return 0 ;
    LL d=N-1 ,t=p ,re=1 ;

    while (d){
        if (d&1)re=(re*t)%N ;
        t=(t*t)%N ;
        d/=2 ;
    }
    return re ;
}

int prime[]={3,11} ;

bool is_prime(int N ){
    for (int i=0 ;i<2 ; i++ )
        if (N!=prime[i] && modual(N,prime[i])!=1)return 0 ;
    return 1 ;
}

int main(){
    int N ;
    while (~scanf("%d",&N )){
        puts(is_prime(N)?"質數":"非質數") ;
    }
}
